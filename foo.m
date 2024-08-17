t = linspace(0, 10, 52047);

figure
subplot(1, 3, 1);
plot(t, actual_output(:, 1), t, filtered_output(:, 1))

subplot(1, 3, 2);
plot(t, actual_output(:, 2), t, filtered_output(:, 2))

subplot(1, 3, 3);
plot(t, actual_output(:, 3), t, filtered_output(:, 3))