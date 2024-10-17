function [waypoints, waypoint_mat] = waypoint_gen()
    close all
    % Import the Map
    cplx_map = load('complexMap_air_ground.mat');
    map = cplx_map.map;
    occupancy_grid = cplx_map.logical_map;
    occupancy_grid = flipud(occupancy_grid);
    figure(1)
    show(map);

    % Expand the occupancy grid
    buffer_size = 8;
    expanded_grid = imdilate(occupancy_grid, strel('square', 2*buffer_size+1));

    % Generate random waypoints
    num_waypoints = 4;
    [free_row, free_col] = find(expanded_grid == 0);
    free_cells = [free_row, free_col];
    % Randomly select waypoints from free cells
    num_free_cells = size(free_cells, 1);
    selected_indices = randperm(num_free_cells, num_waypoints);
    waypoints = free_cells(selected_indices, :);

    % Visualize the occupancy grid and waypoints
    figure(2);
    [exp_row, exp_col] = find(expanded_grid == 1);
    scatter(exp_col, exp_row, 'red');
    hold on;
    [occ_row, occ_col] = find(occupancy_grid == 1);
    scatter(occ_col, occ_row, 1, 'black');
    axis equal
    axis xy
    hold on;
    % Scatter plot for waypoints (swap column and row for visualization)
    scatter(waypoints(:,2), waypoints(:,1), 50, 'blue', 'filled');
    title('Occupancy Grid with Waypoints and Buffer');
    xlabel('X');
    ylabel('Y');
    hold off;

    % Apply TSP algorithm to optimize waypoint order
    world_start = [2,2];
    world_waypoints = grid2world(map, waypoints);
    
    % Include start point in the TSP calculation
    all_points = [world_start; world_waypoints];
    num_points = size(all_points, 1);
    
    % Calculate distances between all points
    distances = pdist2(all_points, all_points);
    
    % Generate all possible permutations of waypoint orders
    waypoint_indices = 2:num_points;  % Start point (index 1) is fixed
    permutations = perms(waypoint_indices);
    
    % Initialize variables for the shortest path
    shortestPath = Inf;
    bestOrder = [];
    
    % Evaluate all permutations
    for i = 1:size(permutations, 1)
        currentOrder = [1, permutations(i, :)];
        currentDistance = 0;
        
        % Calculate total distance for this permutation
        for j = 1:num_points-1
            currentDistance = currentDistance + distances(currentOrder(j), currentOrder(j+1));
        end
        
        % Update if this is the shortest path found so far
        if currentDistance < shortestPath
            shortestPath = currentDistance;
            bestOrder = currentOrder;
        end
    end
    
    % Reorder waypoints based on the best order found
    sorted_world_waypoints = all_points(bestOrder(2:end), :);
    sorted_grid_waypoints = world2grid(map, sorted_world_waypoints);

    % Visualize sorted waypoints
    figure(3);
    scatter(occ_col, occ_row, 1, 'black');
    hold on;
    scatter(sorted_grid_waypoints(:,2), sorted_grid_waypoints(:,1), 50, 'blue', 'filled');
    % Add labels to sorted waypoints
    for i = 1:size(sorted_grid_waypoints, 1)
        text(sorted_grid_waypoints(i,2), sorted_grid_waypoints(i,1), num2str(i), 'Color', 'white', 'FontWeight', 'bold', ...
            'HorizontalAlignment', 'center', 'VerticalAlignment', 'middle');
    end
    title('Sorted Waypoints with Optimal Path');
    xlabel('Column');
    ylabel('Row');
    axis equal
    axis xy
    hold off;

    % Plan paths using A* planner
    % inflated_map = map.copy();
    % inflate(inflated_map, 0.7);
    % planner = plannerAStarGrid(inflated_map);
    % % planner = plannerAStarGrid(map);
    % start = world2grid(map, world_start);
    % % Flip first axis to align with convention used so far
    % sorted_grid_waypoints(:,1) = 410 - sorted_grid_waypoints(:,1);
    % % Calculate paths between all waypoints
    % num_paths = num_waypoints; % Including path from start to first waypoint
    % paths = cell(1, num_paths);
    % % Path from start to first waypoint
    % paths{1} = plan(planner, start, sorted_grid_waypoints(1,:));
    % % Paths between waypoints
    % for i = 1:num_waypoints-1
    %     paths{i+1} = plan(planner, sorted_grid_waypoints(i,:), sorted_grid_waypoints(i+1,:));
    % end
    % world_paths = cellfun(@(p) grid2world(map, p), paths, 'UniformOutput', false);

    % % Optimize paths
    % options = optimizePathOptions;
    % options.ObstacleSafetyMargin = 1.0;
    % options.MaxPathStates = 400;
    % options.NumIteration = 1;
    % options.MaxSolverIteration = 10;
    % [opt_paths,kineticInfo,solutionInfo] = cellfun(@(p) optimizePath(p, map, options), world_paths, 'UniformOutput', false);

    % Visualize all paths
    % figure(5);
    % show(map)
    % hold on
    % colors = lines(num_paths);
    % for i = 1:num_waypoints
    %     path = world_paths{i};
    %     % path = opt_paths{i};
    %     plot(path(:,1), path(:,2), 'Color', colors(i,:), 'LineWidth', 2);
    % end

    newx = abs(sorted_world_waypoints(:, 1));
    newy = abs(-41+sorted_world_waypoints(:, 2));

    waypoints = struct('x',{newx},'y',{newy});

    sorted_world_waypoints2(:,1) = newx;
    sorted_world_waypoints2(:,2) = newy; 

    waypoint_mat = sorted_world_waypoints2;

    % waypoint_mat = [10,10;25,25;30,30;40,40];
    % waypoints = struct('x',{[10,25,30,40]'},'y',{[10,25,30,40]'});
    
end