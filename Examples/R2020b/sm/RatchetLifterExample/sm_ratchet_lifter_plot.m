% Code to plot simulation results from sm_ratchet_lifter
%% Plot Description:
%
% This plot shows the position and velocity of the traveler in the vertical
% direction.

% Copyright 2020 The MathWorks, Inc.

% Generate simulation results if they don't exist
if ~exist('simlog_sm_ratchet_lifter', 'var')
    sim('sm_ratchet_lifter')
end

% Get simulation results
simlog_t = simlog_sm_ratchet_lifter.Ratchet_Lifter.Traveler_Pin_Slot.Px.p.series.time;
simlog_p = simlog_sm_ratchet_lifter.Ratchet_Lifter.Traveler_Pin_Slot.Px.p.series.values('cm');
simlog_v = simlog_sm_ratchet_lifter.Ratchet_Lifter.Traveler_Pin_Slot.Px.v.series.values('cm/s');


% Plot results
simlog_handles(1) = subplot(2, 1, 1);
plot(simlog_t, simlog_p, 'LineWidth', 1)
title('Traveler')
grid on
ylabel('Position (cm)')
simlog_handles(2) = subplot(2, 1, 2);
plot(simlog_t, simlog_v, 'LineWidth', 1)
% title('Printing Head Position along the y-axis')
grid on
ylabel('Velocity (cm/s)')
box on
xlabel('Time (s)')

% Remove temporary variables
clear simlog_t simlog_p simlog_v
