function state_kp1 = robotModel(state_k,v, omega, dt)

    % Extract current state
    x = state_k(1);
    y = state_k(2);
    theta = state_k(3);

    % Update state using kinematic equations
    x_new = x + v * cos(theta) * dt;
    y_new = y + v * sin(theta) * dt;
    theta_new = theta + omega * dt;

    % Wrap the angle to [-pi, pi]
    theta_new = wrapToPi(theta_new);

    % Return new state
    state_kp1 = [x_new; y_new; theta_new];
end



