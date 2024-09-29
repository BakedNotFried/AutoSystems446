%% Setup inital values for the simulation
function [scanAngles, path_a_star] = setupParams()
    % LiDAR
    fov = 60;
    fov = fov * pi/180;
    numReturns = 25;
    scanAngles = linspace(-fov, fov, numReturns);

    % Basic A* Path
    cplx_map = load('complexMap_air_ground.mat');
    map = cplx_map.map;
    
    % init a planner....
    planner = plannerAStarGrid(map);

    % Define a a start and goal...
    start = [20 20];
    goal = [248 248];

    path_a_star = plan(planner,start,goal);
end