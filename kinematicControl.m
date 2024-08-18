%% main
clc; close all; clear;

  % Simulation parameters
    dt = 0.01;   % Time step
    T = 50;      % Total simulation time

    % iniital state/pose
    state = [0; 0; 90*pi/180];  % Initial position (0,0) and orientation (90 degrees)
    % goal pose
    goalPose = [ 10 5 90*pi/180];

   % Control inputs [v; omega]
    v = 0.0;     % Linear velocity (m/s)
    omega = 0.0; % Angular velocity (rad/s)

    % Pre-allocate storage for states
    num_steps = T / dt;
    states = zeros(3, num_steps);
    controls = zeros(2, num_steps);
    states(:, 1) = state;

  

    for k = 2:num_steps
        
        %% Students to complete - Perform control
        % controller 1
        % [v, omega,stop] = controller1(state,goalPose);
        
        % student to try as an exercise
        % controller 2
         [v, omega,stop] = controller2(state,goalPose);
      

        %% define a safeguards to end simulation
        if stop==1
             v=0;
             omega=0;
        end 

        %% Update state
        state = robotModel(state, v, omega, dt);
        states(:, k) = state;
        controls(:,k) = [v omega];

         
        
    end
    Xg = states(1, end);
    Yg = states(2, end);
    Thetag = 180*states(3, end)/pi;

   % Plot results
    figure(1);
    plot(states(1, :), states(2, :), 'b.', 'LineWidth', 2); 
    
        hold on;
   
    xlabel('X position (m)');
    ylabel('Y position (m)');
    title('Unicycle Path');
    grid on;


   % plot orientation at start
    p2 = [states(1, 2)  states(2, 2)];          % second Point
    p1 = [states(1, 1)  states(2, 1) ];         % first Point
    dp = p2-p1;                               % Difference
    quiver(p1(1),p1(2),dp(1),dp(2),40,'LineWidth',2,'Color','red'); % approaching angle

    % plot orientation at goal
    p2 = [states(1, end)+0.5*cos(state(3,end)) , states(2, end)+0.5*sin(state(3,end))];%goalPose(1)  goalPose(2)];          % second Point
    p1 = [states(1, end), states(2, end) ];    % first Point
    dp = p2-p1;                               % Difference
    quiver(p1(1),p1(2),dp(1),dp(2),3,'LineWidth',2,'Color','green'); % approaching angle
    hold off;



function [v , omega,stop] = controller1(robotPose,goalPose)

    stop = 0;
    dx = goalPose(1)-robotPose(1);
    dy = goalPose(2)-robotPose(2);
    rho = sqrt(dx^2+dy^2);
    gamma = atan2(dy,dx);
    theta = robotPose(3);
    alpha = angdiff(theta,gamma);
    v = 0.2*rho;
    omega = 0.7*angdiff(theta,gamma);

    if rho < 0.2
        stop = 1;
    end
end

function [v , omega,stop] = controller2(robotPose,goalPose)

stop=0;
dx = goalPose(1) - robotPose(1);
dy = goalPose(2) - robotPose(2);
rho = sqrt(dx^2+dy^2);
gamma = atan2(dy,dx);
theta = robotPose(3);

theta_star = goalPose(3);

alpha = angdiff(theta,gamma);
beta = angdiff(theta_star,gamma);

v = 0.2*rho*cos(alpha);
omega = 0.2*alpha+0.3*beta;


if rho < 0.2
    stop = 1;
end

end