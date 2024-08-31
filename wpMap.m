
function [waypoints,waypoint_mat,path,shortestPath] = setupMap()
close all

    wp.x = (randi(50,10,1)-25)*20;
    wp.y = (randi(50,10,1)-25)*20;
    
    % wp.x = [ 0,50,100,150,200,250,250,250,250,200];
    % wp.y = [50,50,50, 50, 50, 100,150,200,250,250];
    %generate edges
    map = [];
    edges = [];
    
    for i = 1:10
        nx = wp.x(i);
        ny = wp.y(i);
        for j = 1:10       
            cnx = wp.x(j);
            cny = wp.y(j);
            Nlength = sqrt((nx-cnx)^2 + (ny-cny)^2);
            edges = [edges,Nlength];    
        end    
        map = [map;edges];
        edges = [];
    end
    
    %map;
    
    %randomise the number of points
    randpoints = [1:10];
    mapindex = perms(randpoints);
    
    shortestPath = 99999999999;
    currentLinks = [];
    [xwp,ywp] = size(mapindex);
    for i = 1:xwp
        points = mapindex(i,:);
        pathlen = 0;
        for j = 1:9
            item1 = points(j);
            item2 = points(j+1);
            pathlen = pathlen+map(item1,item2);
        end
        if pathlen < shortestPath
            currentLinks = points;
            shortestPath = pathlen;
        end
    end
    % 
    % currentLinks;
    % randpoints;
        
    waypoints.x = zeros(10,1);
    waypoints.y = zeros(10,1);    
    waypoints.x = [0;waypoints.x];
    waypoints.y = [0;waypoints.y];


    for i = 2:11     
        waypoints.x(i) = wp.x(currentLinks(i-1));
        waypoints.y(i) = wp.y(currentLinks(i-1));
    end
    dist = sqrt(waypoints.x(2)^2+waypoints.y(2)^2);
    shortestPath = shortestPath+dist;

    t = 1:numel(waypoints.x);
    tq = 1:0.2:t(end);
    xq = interp1(t,waypoints.x,tq,'v5cubic');
    yq = interp1(t,waypoints.y,tq,'v5cubic');
   
    path.x = xq;
    path.y = yq;

    waypoint_mat = [];
    for i = 1:11
        waypoint_mat = [waypoint_mat;waypoints.x(i),waypoints.y(i)];
    end
end
