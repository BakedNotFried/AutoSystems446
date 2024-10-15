close all
    %% Import the Map
    cplx_map = load('complexMap_air_ground.mat');
    occupancy_map = cplx_map.map;
    original_logic_map = cplx_map.logical_map;

    %% Set the Obstacles to be illigal points for WP gen
    obstacles = load('obstacles_air_ground.mat');

    obstacles_grid = world2grid(occupancy_map, obstacles.obstacles(:, 1:2));
    logical_map = original_logic_map; % Load into the simulink sim...
    
    for i = 1:1:numel(obstacles_grid(:, 1))
        logical_map(obstacles_grid(i, 1), obstacles_grid(i, 2)) = 1;
    end

    occupancy_map = binaryOccupancyMap(logical_map, 10);
    
    % inflate the map so we dont get waypoints on the wall...
    inflate(occupancy_map, 0.5);
    
    % convert the map to its logical values...
    logic_map = occupancyMatrix(occupancy_map);
    
    %% Generate random waypoints
    % setup the generation params...
    num_waypoints = 4;
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
    
    %% Clean up Variables for Export
    % Translate values to occupancy map...
    waypoints_world = grid2world(occupancy_map, [dist_wp.x; dist_wp.y]');
    
    waypoints.x = waypoints_world(:, 1);
    waypoints.y = waypoints_world(:, 2);
    
    waypoint_mat = [dist_wp.x; dist_wp.y];