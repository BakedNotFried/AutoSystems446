%% Setup inital values for the simulation
function [scanAngles] = setupParams()
    % LiDAR
    fov = 60;
    fov = fov * pi/180;
    numReturns = 3;
    scanAngles = linspace(-fov, fov, numReturns);
end