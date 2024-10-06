close all
%% Import the Map
cplx_map = load('complexMap_air_ground.mat');
occupancy_map = cplx_map.map;
original_logic_map = cplx_map.logical_map;

% inflate the map so we dont get waypoints on the wall...
inflate(occupancy_map, 0.5);

% convert the map to its logical values...
logic_map = occupancyMatrix(occupancy_map);

%% Generate random waypoints
% setup the generation params...
num_waypoints = 5;
sample = 500;
wp.x = [];
wp.y = [];

start = [385, 25];

% Generate a sample of random cordinates...
points_x = round(randi([1, 410], sample, 1));
points_y = round(randi([1, 520], sample, 1));

% Loop over the generated cords and extract waypoints that exist in a valid
% region of the inflated map...
for i = 1:1:sample
    if (numel(wp.x) < num_waypoints)
        if ~logic_map(points_x(i), points_y(i)) 
            wp.x = [wp.x, points_x(i)];
            wp.y = [wp.y, points_y(i)];
        end
    end
end

% Use Set WP's
wp.x = [58, 260, 344, 186, 395];
wp.y = [19, 237, 76, 353, 266];

% Sanity Plot...
figure
subplot(1, 2, 1)
imshow(1 - original_logic_map)
hold on
plot(wp.y, wp.x, 'b*')
plot(start(2), start(1), 'r*')
plot([25, wp.y], [385, wp.x], '--')

%% Plan an un-ordered path via A*
wp_path_unordered = [];
start = [385, 25];

goal = [wp.x(1), wp.y(1)];
wp_path_unordered = [wp_path_unordered, plan(planner,start,goal(1,:))'];

for i = 1:1:num_waypoints - 1
    % update the start point...
    start = [wp.x(i), wp.y(i)];
    
    % update the goal...
    goal = [wp.x(i + 1), wp.y(i + 1)];

    % plan the path and append...
    wp_path_unordered = [wp_path_unordered, plan(planner,start,goal(1,:))'];
end
plot(wp_path_unordered(2,:), wp_path_unordered(1,:), 'r-')

unorderedPathSize = num2str(numel(wp_path_unordered(1,:)));
title({ 'Waypoints Unchanged from Generation' ; ['Path Size: ', unorderedPathSize] })

%% Plan a path via A*
% Psudo-sort the waypoints on distance locations...
dist_wp = [];

% Setup the second subplot
subplot(1, 2, 2)
imshow(1 - original_logic_map)
hold on
plot(wp.y, wp.x, 'b*')

for i = 1:1:num_waypoints
    % find closes wp...
    [M, I] = min(sqrt((wp.x - start(1)).^2+(wp.y - start(2)).^2));

    % assign to "sorted" wp map...
    dist_wp.x(i) = wp.x(I);
    dist_wp.y(i) = wp.y(I);

    % set as new start...
    start = [wp.x(I), wp.y(I)];

    % drop element from array...
    wp.x(I) = [];
    wp.y(I) = [];
end

plot([25, dist_wp.y], [385, dist_wp.x], '--')

% init a planner....
planner = plannerAStarGrid(occupancy_map);

% plan a path using A* planner...
wp_path = [];
start = [385, 25];

goal = [dist_wp.x(1), dist_wp.y(1)];
wp_path = [wp_path, plan(planner,start,goal(1,:))'];

% plot the starting point
plot(start(2), start(1), 'r*')

for i = 1:1:num_waypoints - 1
    % update the start point...
    start = [dist_wp.x(i), dist_wp.y(i)];
    
    % update the goal...
    goal = [dist_wp.x(i + 1), dist_wp.y(i + 1)];

    % plan the path and append...
    wp_path = [wp_path, plan(planner,start,goal(1,:))'];
end

% Sanity Plot
plot(wp_path(2,:), wp_path(1,:), 'g-')

orderedPathSize = num2str(numel(wp_path(1,:)));
title({'Waypoints Ordered by Closest Ecludian Distance' ; ['Path Size: ', orderedPathSize] })

sgtitle(sprintf('Generated A* Paths\n Unordered Waypoints vs Ordered Waypoints'))