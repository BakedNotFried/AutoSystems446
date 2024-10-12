%% Setup inital values for the simulation
function [scanAngles] = setupParams()
    % LiDAR
    fov = 90;
    fov = fov * pi/180;
    numReturns = 8;
    scanAngles = linspace(-fov, fov, numReturns);
end 