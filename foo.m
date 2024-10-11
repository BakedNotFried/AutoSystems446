close all
% Import the Map
cplx_map = load('complexMap_air_ground.mat');
occupancy_map = cplx_map.map;
original_logic_map = cplx_map.logical_map;


foo = binaryOccupancyMap(original_logic_map, 10)

figure
show(foo)

figure
show(occupancy_map)