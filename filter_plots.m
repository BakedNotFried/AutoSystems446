
% Parameterise Output Data
noisy_x = noisyStateOutput(:, 1);
noisy_y = noisyStateOutput(:, 2);
noisy_theta = noisyStateOutput(:, 3);

filt_x = filteredStateOutput(:, 1);
filt_y = filteredStateOutput(:, 2);
filt_theta = filteredStateOutput(:, 3);

% Subsect the output data
sz = size(noisyStateOutput);

t = linspace(1, 10, sz(1));

figure
title('Filter Output')
subplot(1, 2, 1)
plot(t(1:200), noisy_x(1:200), "LineStyle", "-", "LineWidth", 2, "color", "b")
xlabel('Time (seconds)')
ylabel('X (meters)')
title('noisy x channel')
grid

subplot(1, 2, 2)
plot(t(1:200), filt_x(1:200), "LineStyle", "-", "LineWidth", 2, "color", "r")
xlabel('Time (seconds)')
ylabel('X (meters)')
title('filtered x channel')
grid

sgtitle(sprintf('Noisy X State Channel vs Filtered X State Channel\n First 200 Samples'))

figure
title('Filter Output')
subplot(1, 2, 1)
plot(t(1:200), noisy_y(1:200), "LineStyle", "-", "LineWidth", 2, "color", "b")
xlabel('Time (seconds)')
ylabel('Y (meters)')
title('noisy y channel')
grid
subplot(1, 2, 2)
plot(t(1:200), filt_y(1:200), "LineStyle", "-", "LineWidth", 2, "color", "r")
xlabel('Time (seconds)')
ylabel('Y (meters)')
title('filtered y channel')
grid

sgtitle(sprintf('Noisy Y State Channel vs Filtered Y State Channel\n First 200 Samples'))

figure
title('Filter Output')
subplot(1, 2, 1)
plot(t(1:200), noisy_theta(1:200), "LineStyle", "-", "LineWidth", 2, "color", "b")
title('noisy θ channel')
xlabel('Time (seconds)')
ylabel('θ (rad)')
grid

subplot(1, 2, 2)
plot(t(1:200), filt_theta(1:200), "LineStyle", "-", "LineWidth", 2, "color", "r")
title('filtered θ channel')
xlabel('Time (seconds)')
ylabel('θ (rad)')
grid

sgtitle(sprintf('Noisy θ State Channel vs Filtered θ State Channel\n First 200 Samples'))

% Kalman Filter Gain Data
k_gain_x = kalamanFilterGain(1, :);
k_gain_y = kalamanFilterGain(1, :);
k_gain_theta = kalamanFilterGain(1, :);

figure
title('Filter Output')
subplot(1, 3, 1)
plot(t(1:200), k_gain_x(1:200), "LineStyle", "-", "LineWidth", 2, "color", "g")
title('Kalman Gain x channel')
xlabel('Time (seconds)')
ylabel('Filter Gain')
grid

subplot(1, 3, 2)
plot(t(1:200), k_gain_y(1:200), "LineStyle", "-", "LineWidth", 2, "color", "g")
title('Kalman Gain y channel')
xlabel('Time (seconds)')
ylabel('Filter Gain')
grid

subplot(1, 3, 3)
plot(t(1:200), k_gain_theta(1:200), "LineStyle", "-", "LineWidth", 2, "color", "g")
title('Kalman Gain θ channel')
xlabel('Time (seconds)')
ylabel('Filter Gain')
grid

sgtitle(sprintf('Kalman Filter Preformance All State Channels \n First 200 Samples, R Gain = 0.005'))

%% X Channel Preformance
figure
subplot(1, 2, 1)
title('Noisy X State Channel vs Filtered X State Channel')
hold on
plot(t, noisy_x, 'Marker', ".", "linestyle", "none", "color", "b")
plot(t, filt_x, "LineStyle", "-", "LineWidth", 2, "color", "r")
xlabel('Time (seconds)')
ylabel('X (meters)')
legend('X Noisy', 'X Filtered')
grid

subplot(1, 2, 2)
plot(t, k_gain_x, "LineStyle", "-", "LineWidth", 2, "color", "g")
title('Kalman Gain X channel')
xlabel('Time (seconds)')
ylabel('Gain K')
legend('Filter Gain')
grid

sgtitle(sprintf('Kalman Filter Preformance X State Channel'))

%% Y Channel Preformance
figure
subplot(1, 2, 1)
title('Noisy Y State Channel vs Filtered Y State Channel')
hold on
plot(t, noisy_y, 'Marker', ".", "linestyle", "none", "color", "b")
plot(t, filt_y, "LineStyle", "-", "LineWidth", 2, "color", "r")
xlabel('Time (seconds)')
ylabel('Y (meters)')
legend('Y Noisy', 'Y Filtered')
grid

subplot(1, 2, 2)
plot(t, k_gain_y, "LineStyle", "-", "LineWidth", 2, "color", "g")
title('Kalman Gain Y channel')
xlabel('Time (seconds)')
ylabel('Gain K')
legend('Filter Gain')
grid

sgtitle(sprintf('Kalman Filter Preformance Y State Channel'))

%% Theta Channel Preformance
figure
subplot(1, 2, 1)
title('Noisy θ State Channel vs Filtered θ State Channel')
hold on
plot(t, noisy_theta, 'Marker', ".", "linestyle", "none", "color", "b")
plot(t, filt_theta, "LineStyle", "-", "LineWidth", 2, "color", "r")
xlabel('Time (seconds)')
ylabel('θ (rad)')
legend('θ Noisy', 'θ Filtered')
grid

subplot(1, 2, 2)
plot(t, k_gain_theta, "LineStyle", "-", "LineWidth", 2, "color", "g")
title('Kalman Gain θ channel')
xlabel('Time (seconds)')
ylabel('Gain K')
legend('Filter Gain')
grid

sgtitle(sprintf('Kalman Filter Preformance θ State Channel'))

