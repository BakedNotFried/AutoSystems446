clc
format short
x11 = Time_out(end)/60;
x2 = sum(abs(distance_out));
x3 = shortestPath;
disp('---------------------------------------------------------------------');
X11 = sprintf('Mission Time: %f seconds',x11);
X2 = sprintf('est distance traveled: %f m',x2);
X3 = sprintf('Actual Path Distance %f',x3);
disp(X11);
disp(X2);
disp(X3);

t = Time_out/60;

figure()
sgtitle(sprintf('Vehicle Error Report Graphs'))
subplot(2,1,1)
plot(t,tr_err)
grid on
title('Tracking Error Output %')

subplot(2,1,2)
hold on
grid on
wp_inverted = -wp_err;
[pks,locs] = findpeaks(-wp_err,t,'MinPeakProminence',4);
plot(t,wp_err,locs,-pks,'o');
text(locs+.05,-pks,num2str((1:numel(-pks))'));
title('Waypoint distance Error Output %')



