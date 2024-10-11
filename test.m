function out_path = test(logical_map,start,goal)
    
    % Generate an occupancy map
    occupancy_map = binaryOccupancyMap(logical_map, 10);
    
    % Generate a path from current pose to desired waypoint
    path_start = world2grid(occupancy_map, [start(1), start(2)]);
    path_goal = world2grid(occupancy_map, [goal(1), goal(2)]);
    
    planner = plannerAStarGrid(occupancy_map);
    grid_path = plan(planner, round(path_start), round(path_goal));
        
    path = grid2world(occupancy_map, grid_path);
    
    out_path.x = path(:,1);
    out_path.y = path(:,2);
end
