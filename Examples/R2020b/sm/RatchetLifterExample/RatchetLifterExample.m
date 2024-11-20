%% Ratchet Lifter
% This example models a ratchet lifter and demonstrates how to use contact proxies for contact problems that involve complex geometries.
%  
% In this example, as the traveler handle is pumped up and down, the traveler climbs up along the toothed rack to lift a load. 
% To simplify the contacts between the toothed rack and climbers, 
% the model represents the rack teeth and climber shaft-pins with proxies, such as cylinders and spheres, and simulates the contacts between these proxies. 
% Copyright 2020 The MathWorks, Inc.

%%
%% Model
open_system('sm_ratchet_lifter');
set_param('sm_ratchet_lifter','SimMechanicsOpenEditorOnUpdate','off');
%% Subsystems
% The ratchet lifter consists of five subsystems: the Toothed Rack, Traveler, Neg Climber, Pos Climber, 
% and Contact subsystems. The <docid:sm_ref#btqto3o-1> block connects the toothed rack and traveler. The climbers are connected by the traveler and <docid:sm_ref#bs1gcce-1> block. 

open_system('sm_ratchet_lifter/Ratchet Lifter','force');

%% Contact Simulation
% The <docid:sm_ref#mw_42c86d36-73b4-42f9-9034-f575972f2738> blocks that are used to model the contact forces between the climbers and rack teeth are 
% housed in the Contact subsystems.

open_system('sm_ratchet_lifter/Ratchet Lifter/Contacts Left/Climber to SlantCyl','force');

%% Animation and Proxies
%
% <<../Lifter.gif>>
%
% The image shows the proxies of the rack teeth and climber cylinders.
%
% <<../ratchet_lifter_contact_proxies.png>>
%

%% Simulation Results
% This plot shows the position and velocity of the middle pin of the traveler. 
sm_ratchet_lifter_plot
set_param('sm_ratchet_lifter','SimMechanicsOpenEditorOnUpdate','on');
 
%%
close all
bdclose all
clear all

