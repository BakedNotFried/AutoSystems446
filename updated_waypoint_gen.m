% Basic A* Path
close all, clc

cplx_map = load('complexMap_air_ground.mat');
occupancy_map = cplx_map.map;
original_logic_map = cplx_map.logical_map;

% inflate the map so we dont get waypoints on the wall...
inflate(occupancy_map, 0.5);

% convert the map to its logical values...
logic_map = occupancyMatrix(occupancy_map);

% setup the generation params...
num_waypoints = 5;
sample = 500;
wp.x = [];
wp.y = [];

start = [410 - 25, 25];

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

% Sanity Plot...
figure
imshow(1 - original_logic_map)
hold on
plot(wp.y, wp.x, 'b*')
plot(start(2), start(1), 'r*')

% Psudo-sort the waypoints on distance locations...
dist_wp = [];
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

% % init a planner....
% planner = plannerAStarGrid(occupancy_map);
% 
% % Define a a start and goal...
% start = [start(1), start(2)];
% goal = [wp.x; wp.y]';
% 
% plan(planner,start,goal(1,:));
% figure
% show(planner)