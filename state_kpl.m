function state_kpl(state_k,v,omega,dt)

%extract current state
x = state_k(1);
y = state_k(2);
theta =state_k(3);

x_new = x+v*cos(theta)*dt;
y_new = x+v*sin(theta)*dt;
theta_new = theta*omega*dt;

theta_new = wrapToPi(theta_new);

state_kp1 = [x_new,y_new,theta_new];

end