
function [waypoints,waypoint_mat,path] = setupMap()
close all

    % wp.x = (randi(50,10,1)-25)*20;
    % wp.y = (randi(50,10,1)-25)*20;

    wp.x = [ 20,120,360,420,320,80,260,120,-20,-460];
    wp.y = [400,480,220,0,20,-20,-260,-320,-460,-300];
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
    % shortestPath;
    
    waypoints.x = zeros(10,1);
    waypoints.y = zeros(10,1);
    
    for i = 1:10     
        waypoints.x(i) = wp.x(currentLinks(i));
        waypoints.y(i) = wp.y(currentLinks(i));
    end
    
    % %plotting
    % figure(1)
    % hold on;
    % labels = {'1','2','3','4','5','6','7','8','9','10'};
    % plot(wp.x,wp.y,'k*')
    % plot(waypoints.x,waypoints.y,'b-.')
    % 
    t = 1:numel(waypoints.x);
    tq = 1:0.2:t(end);
    xq = interp1(t,waypoints.x,tq,'v5cubic');
    yq = interp1(t,waypoints.y,tq,'v5cubic');
    % plot(waypoints.x,waypoints.y,'bo',xq,yq,'ro-.');
    % 
    % text(waypoints.x-7,waypoints.y+40,labels,color='r');
    % text(wp.x-7,wp.y-30,labels,color='b');
    % 
    % xlim([-500,500]);
    % ylim([-500,500]);
    % grid on;
    % set(gca,'XMinorTick','on')
    % 
    path.x = xq;
    path.y = yq;
    % 
    % figure(2)
    % title('dummy map')
    waypoint_mat = [];
    for i = 1:10
        waypoint_mat = [waypoint_mat;waypoints.x(i),waypoints.y(i)];
    end
end
