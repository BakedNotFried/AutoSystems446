    % kalman test
    % 
function extKalmanPrac(x,y,th,vx,vy,vth,dt)
    
    %     close all;
    clf;
    dt = 1;
    % fill in A
    A = [1 0 0 dt 0 0;
         0 1 0 0 dt 0;
         0 0 1 0 0 dt;
         0 0 0 1 0 0;
         0 0 0 0 1 0;
         0 0 0 0 0 1];

    
    % fill in B
    B = [(dt^2)/2,0,0; 
        0,(dt^2)/2,0; 
        0,0,(dt^2)/2;
        dt,0,0; 
        0,dt,0;
        0,0,dt];
    
    sigmaV = 1;        
    R = [0.001,0,0,0,0,0;
         0,0.001,0,0,0,0;
         0,0,0.001,0,0,0;
         0,0,0,sigmaV^2,0,0;
         0,0,0,0,sigmaV^2,0
         0,0,0,0,0,sigmaV^2];
        
    
    %% fill in H
    H = [1,0,0,0,0,0;
         0,1,0,0,0,0;
         0,0,1,0,0,0];
    
    path = [0,0];
    for k = 1:9
       path = [path;k*10,k*10]; 
    end
    
    figure(1);
    hold on;
    grid on;
    axis([-100,100,-100,100]);
    scatter(path(:,1),path(:,2),'bo');
    
    %initial guess
    goal = [90,90];
    %muX = [x0 y0 vx0 vy0]';
    
    SigmaX = 1 * eye(6);
    target = [100,100];
    % standard deviation of the measurements +- 35 m
    % fill in Q
    sigmaW = 0.1;
    Q = [sigmaW^2 0 0;
         0 sigmaW^2 0
         0 0 sigmaW^2];
    
    % the estimated trajectory
    muX = [0,0,0.5,0.5]';
    x_est = muX;
    x_sigma_est = SigmaX;
    
    done = false;
    RobotPos = [0,0];
    RobotVel = [1,1];
    pathcount = 1;
    i = 0;
    while(~done)
    
    %estimate Range of target using the camera
    %         z = Z(:,i);
    %         i = i+1; 
        muX(1:2) = RobotPos;
        muX(3:4) = RobotVel;
        
        z = [path(pathcount,1),path(pathcount,2)];
        xd = z-RobotPos;
        dist = sqrt(xd(1,1)^2 + xd(1,2)^2);
        if(dist < 2)
           if pathcount == length(path)
               done = true;
               break;
           else
               pathcount = pathcount +1;
               fprintf('current path step');
               disp(pathcount)
               continue;
           end
        end
    %estimate position of next move;
    
        
        muX = A*muX;
        muXest = muX;
        SigmaX = A*SigmaX*A' + R;
        
        % correct (or update) step
        K1 = SigmaX *H';
        K2 = H*SigmaX *H'+Q;
    
        K = K1/K2;
        r = z' - H*muX;
    %         muX = muX +*r;
        muX = muX + K*r;
        SigmaX = (eye(4) -K *H)*SigmaX;
        RobotPos = [muX(1,1),muX(2,1)];
    %         fprintf()
        % add the current estimate to the trajectory 
        x_est = [x_est,muX];
        x_sigma_est  = SigmaX; 
        scatter(RobotPos(1,1),RobotPos(1,2),'ko');
    %         scatter(muXest(1,1),muXest(2,1),'r*');
    %         plot_cov(muX,SigmaX , 3);
    %         pause(1); 
    end
    
    figure(1)
    hold on;
    grid on;
    axis([-100,100,-100,100]);
    for i=1:length(x_est)
        plot_cov(x_est(1:2,i),x_sigma_est{i} , 3);
    end
    scatter(x_est(1,:),x_est(2,:),25,'ro');
    % legend(3 sigmas bound of estimated position")
    
    end
    
    function vectorDist = psuedoRange(pos,goal)
    
    vectorDist = goal-pos;
    %     dist = sqrt(vectorDist(1,1)^2 + vectorDist(1,2)^2);
    %     noise = rand()/100;
    %     out = dist;
    
end
    
    
    %helping function to plot the covariance matrix on x and y as an ellipse at a given number of sigmas
    function plot_cov(muX,SigmaX,number_of_sigmas)
    SigmaX = SigmaX(1:2,1:2); 
    muX = muX(1:2);
    if(~any(diag(SigmaX)==0))
        [V,D] = eig(SigmaX);
        y = number_of_sigmas*[cos(0:0.1:2*pi);sin(0:0.1:2*pi)];
        el = V*sqrtm(D)*y;
        el = [el el(:,1)]+repmat(muX,1,size(el,2)+1);
        line(el(1,:),el(2,:));
    end
    end
