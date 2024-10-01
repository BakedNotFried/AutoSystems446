%% Setup inital values for the simulation
function [scanAngles] = setupParams()
    % LiDAR
    fov = 60;
    fov = fov * pi/180;
    numReturns = 30;
    scanAngles = linspace(-fov, fov, numReturns);
end