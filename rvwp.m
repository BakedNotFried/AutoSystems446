function [vel,turnRate,stop] = fcn(x,y,th,waypointsx,waypointsy)


persistent WpCounter;
if isempty(WpCounter)
    WpCounter = 1; %% next waypoint
end

persistent Wpprev;
if isempty(Wpprev)
    Wpprev = WpCounter-1; %% waypoint ur currently at
end

 
if(Wpprev == 0)
    Next_wp = [waypointsx(WpCounter),waypointsy(WpCounter)];
    Prev_wp = [0,0];
 else
     Next_wp = [waypointsx(WpCounter),waypointsy(WpCounter)];
     Prev_wp = [waypointsx(Wpprev),waypointsy(Wpprev)];
     %Prev_wp = [0,0];
 end

dist2target = sqrt((Next_wp(2)-y)^2+(Next_wp(1)-x)^2);
distwp2wp = sqrt((Next_wp(2)-Prev_wp(2))^2+(Next_wp(1)-Prev_wp(1))^2);
dist2Last = sqrt((Prev_wp(2)-y)^2+(Prev_wp(1)-x)^2);
unitvec = [Next_wp(1)-Prev_wp(1),Next_wp(2)-Prev_wp(2)]/distwp2wp;

sigma = 10;
targetrel = (dist2Last+10)*unitvec;
target = [targetrel(1)+Prev_wp(1),targetrel(2)+Prev_wp(2)];
thtarget = atan2(target(2)-y,target(1)-x);


%% --- Control Shit ------ 
error = angdiff(th,thtarget);
K_theta = 0.1;
omega = K_theta * error;  % proportional control  - omega is the command
turnRate = omega;


persistent velocity;
if isempty(velocity)
    velocity = 0.5;
end
if(dist2target > 25)
    velocity = velocity+0.001;
    if(velocity >1)
        velocity = 1;
    end
else
    velocity = velocity-0.001;
    if(velocity <0.5)
        velocity = 0.5; 
    end
end
vel = 1;

if(dist2target <= 2)
    Wpprev = WpCounter;
    WpCounter = WpCounter+1;

    if(WpCounter > 10)
        stop = 1;
    else 
        stop = 0;
    end
else    
    stop = 0;
end

