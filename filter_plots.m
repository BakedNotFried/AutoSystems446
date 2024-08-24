% Parameterise Output Data
noisy_x = noisyStateOutput(:, 1);
noisy_y = noisyStateOutput(:, 2);
noisy_theta = noisyStateOutput(:, 3);

filt_x = filteredStateOutput(:, 1);
filt_y = filteredStateOutput(:, 2);
filt_theta = filteredStateOutput(:, 3);

% Subsect the output data
sz = size(noisyStateOutput);

t = linspace(1, 5, sz(1));

figure
title('Filter Output')
subplot(1, 2, 1)
plot(t(1:100), noisy_x(1:100))
title('noisy x channel')
subplot(1, 2, 2)
plot(t(1:100), filt_x(1:100))
title('filtered x channel')

sgtitle(sprintf('Noisy X State Channel vs Filtered X State Channel\n First 100 Samples'))

figure
title('Filter Output')
subplot(1, 2, 1)
plot(t(1:100), noisy_y(1:100))
title('noisy y channel')
subplot(1, 2, 2)
plot(t(1:100), filt_y(1:100))
title('filtered y channel')

sgtitle(sprintf('Noisy Y State Channel vs Filtered Y State Channel\n First 100 Samples'))

figure
title('Filter Output')
subplot(1, 2, 1)
plot(t(1:100), noisy_theta(1:100))
title('noisy θ channel')
subplot(1, 2, 2)
plot(t(1:100), filt_theta(1:100))
title('filtered θ channel')

sgtitle(sprintf('Noisy θ State Channel vs Filtered θ State Channel\n First 100 Samples'))