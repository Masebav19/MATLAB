%% Ratchet Lifter Model

% Copyright 2020 The MathWorks, Inc.
%% Rack Geometry

rack.length = 56; % Length of main rack, cm
rack.width  = 10; % Width of main rack, cm
rack.thick  = 1;  % Thickness of main rack, cm

rack.slot_width         = 1;   % With of slot in middle of main rack, cm
rack.lower_slot_margin  = 5;   % Distance between lower slot semicircle center and bottom of rack, cm
rack.upper_slot_margin  = 11;  % Distance between upper slot semicircle center and top of rack, cm

rack.num_teeth          = 15;  % Number of teeth on one side of the rack
rack.tooth_height       = 2.5; % Tooth height, cm
rack.tooth_width        = 2;   % Tooth width, cm
rack.upper_tooth_margin = 1.5; % Distance between surface of top tooth and top of rack, cm

rack.tooth_cyl_rad = .10;  % Radius of tooth cylinders, cm

rack.base_length = 16; % cm
rack.base_width  = 12; % cm
rack.base_thick  = 5;  % cm


%% Traveler Geometry

traveler.length          = 30;  % Length of main part of traveler, cm
traveler.width           = 4;   % Width of main part of traveler, cm
traveler.thick           = 3;   % Thickness of main part of traveler, cm
traveler.plate_thick     = 0.5; % Thickness of front and back traveler plates, cm;
traveler.mid_hole_length = 12;  % Length of hole in middle of traveler, cm
traveler.end_hole_length = 4;   % Length of hole at non-handle end of traveler, cm
traveler.axle_length     = 4;   % Length of traveler pi/slot and hook axles, cm
traveler.hook_axle_rad            = .4;  % Radius of hook axle, cm
traveler.climber_offset           = 3.0; % Horizontal offsets of climber pins from center, cm

traveler.handle_length  = 20;  % Length of traveler handle, cm
traveler.handle_min_rad = 1.3; % Radius of handle where it attaches to traveler, cm
traveler.handle_max_rad = 1.5; % Radius of distil end of handle, cm
traveler.handle_profile = [ 0 1.3; 19 1.5; 20 1.0 ];


%% Climber Geometry

climber.length     = 12; % Climber length, not counting rounded end caps, cm
climber.width      = 1.5; % Climber width, cm
climber.thick      = 0.5; % Climber thickness, cm
climber.pin_rad    = .5; % cm
climber.pin_length = traveler.thick + 2 * climber.thick + 0.5; % cm
climber.sphere_rad = climber.pin_rad; % cm


%% Hook geometry

hook.width           = 1;    % Width of hook cross section, cm
hook.thick           = 1;    % Thickness of hook, cm
hook.outer_rad       = 2.5;  % Radius of outer hook curve, cm
hook.rack_len        = 4;    % Length of straight part of hook, cm
hook.end_azim        = -200; % Azimuth angle of inner and outer hook curves at distil end, deg
hook.outer_rack_azim = +60;  % Azimuth angle of outer hook curve at end where it connects to rack, deg
hook.eye_rad         = 1.5;  % Outer radius of hook where it connects to axle, cm


%% Dynamics

% Contact parameters
contact.stiffness = 1e5; % N / cm
contact.damping   = 1e3; % N / (cm / s)
contact.xrw       = 1; % mm
contact.mus       = 0.15;
contact.mud       = 0.1;
contact.crit_vel  = 2.0; % cm / s

% Gravity Scale Factor
init.gravity_scale = 1.0; % Scales standard gravity (dimensioonless)

% Climber Spring
climber.spring_stiffness = 1e-2; % N / cm
climber.spring_nat_length = rack.width / 2 - rack.tooth_width; % cm

% Load.  The load makes the hook motion look more realistic, as if it's actually holding something
load.mass = 50; % Mass of load hanging from hook, g
load.dist = 30; % Distance of load below center of hook, cm

% Motion cycle
init.motion_amplitude = 28; % deg
init.motion_omega = 118.0; % deg / s


%% Visualization

% Primary MW colors
color.mw_black      = [   0   0   0 ] / 255;
color.mw_dark_blue  = [  18  86 135 ] / 255;
color.mw_light_blue = [ 149 179 215 ] / 255;
color.mw_red        = [ 120  20  20 ] / 255;
color.mw_orange     = [ 210 120   9 ] / 255;

% Secondary MW colors
color.mw_yellow_2   = [ 255 204   0 ] / 255;
color.mw_red_2      = [ 153  50   0 ] / 255;
color.mw_teal_2     = [  23 140 100 ] / 255;

% Model colors
color.rack_color            = color.mw_light_blue;
color.traveler_color        = color.mw_red;
color.traveler_axle_color   = color.mw_black; % For both pin/slot and hook axles
color.climber_color         = color.mw_orange;
color.climber_pin_color     = color.mw_dark_blue;
color.handle_color          = color.mw_orange;
color.horiz_tooth_cyl_color = color.mw_yellow_2;
color.slant_tooth_cyl_color = color.mw_red_2;
color.climber_sphere_color  = color.mw_teal_2;
color.hook_color            = color.mw_yellow_2;
color.base_color            = color.mw_dark_blue;

% Opacities useful for contact debugging.  This should be set to 1 in final version
color.contact_opacity = 1.0;



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Derived
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


rack.half_width     = rack.width / 2;
traveler.slot_half_width  = rack.slot_width / 2;
climber.half_width  = climber.width / 2;
climber.half_length = climber.length / 2;

rack.slot_length = rack.length - rack.upper_slot_margin - rack.lower_slot_margin;

% Angle slanted tooth edge makes with vertical, rad
rack.tooth_angle = atan(rack.tooth_width / rack.tooth_height);

% Distance between bottom of bottom tooth and bottom of rack, cm
rack.lower_tooth_margin = rack.length - rack.upper_tooth_margin - rack.num_teeth * rack.tooth_height;

% Half the width of the center part of the rack, between the teeth
rack.center_half_width = rack.half_width - rack.tooth_width;

% Generate rack cross section
rack.half_rack_xsect = zeros(2 * rack.num_teeth + 3, 2);
rack.half_rack_xsect(1, :) = [rack.center_half_width, 0];
rack.half_rack_xsect(2, :) = [rack.center_half_width, rack.lower_tooth_margin];
for i = 1:rack.num_teeth
    init.y = rack.lower_tooth_margin + i * rack.tooth_height;
    rack.half_rack_xsect(2 * i + 1, :) = [rack.half_width, init.y];
    rack.half_rack_xsect(2 * i + 2, :) = [rack.center_half_width, init.y];
end
rack.half_rack_xsect(end, :) = ...
    [rack.center_half_width + rack.upper_tooth_margin * tan(rack.tooth_angle), rack.length];

rack.npts = 25;  % Must be odd
rack.angles = linspace(0, pi, rack.npts)';
rack.semicircle = traveler.slot_half_width * [cos(rack.angles), sin(rack.angles)];
rack.slot_xsect = [rack.semicircle + [0, rack.length - rack.upper_slot_margin]; ...
                    flipud(rack.semicircle) .* [+1 -1] + [0, rack.lower_slot_margin] ];

% Reverse order of rack_slot_vertices (since it's a hole), put lowest vertex first, and duplicate
% that vertex at the end.
rack.slot_xsect = circshift(flipud(rack.slot_xsect), -(rack.npts-1)/2);
rack.slot_xsect(end + 1, :) = rack.slot_xsect(1, :);

% Finally, assembly full rack cross-section from pieces
rack.xsect = [ rack.half_rack_xsect; ...                    % Right teeth
                flipud(rack.half_rack_xsect) .* [-1 +1]; ... % Left teeth
                [0 0]; ...                               % Bridge point
                rack.slot_xsect; ...                    % Slot (starting @ bottom)
                [0 0]; ...                               % Bridge point
              ];

% Generate traveler cross section
rack.x1 = traveler.thick / 2;
rack.x0 = rack.x1 - traveler.plate_thick;
rack.y2 = traveler.length / 2;
rack.y1 = rack.y2 - traveler.end_hole_length;
rack.y0 = traveler.mid_hole_length / 2;
traveler.xsect = [...
    0, -rack.y2; +rack.x1, -rack.y2; +rack.x1, +rack.y2; +rack.x0, +rack.y2; +rack.x0, +rack.y1; ...
    -rack.x0, +rack.y1; -rack.x0, +rack.y2; -rack.x1, +rack.y2; -rack.x1, -rack.y2; 0, -rack.y2; ...
    0, -rack.y0; -rack.x0, -rack.y0; -rack.x0, +rack.y0; +rack.x0, +rack.y0; +rack.x0, -rack.y0; 0, -rack.y0; ];

% Generate climber cross section
rack.npts = 25;  % Must be odd
rack.angles = linspace(0, pi, rack.npts)';
rack.semicircle = climber.half_width * [sin(rack.angles), -cos(rack.angles)];
climber.xsect = [rack.semicircle + [+climber.half_length, 0]; ...
                 flipud(rack.semicircle) .* [-1 +1] + [-climber.half_length, 0] ];

% Generate handle cross section
traveler.handle_xsect = [ 0 0; ...
                 circshift(traveler.handle_profile, [0 1]); ...
                 0 traveler.handle_profile(end, 1) ];

% Generate hook cross section
hook.outer_rack_azim_rad = hook.outer_rack_azim * pi / 180; % Convert to radians
hook.end_azim_rad         = hook.end_azim * pi / 180;         % Convert to radians
hook.inner_rad  = hook.outer_rad - hook.width;    % Radius of inner hook curve, cm
hook.offset = [ ... % Offset of center of hook circle rel. to center of hook eye circle
    hook.width/2 - hook.outer_rad * cos(hook.outer_rack_azim_rad), ...
    - hook.rack_len - hook.outer_rad * sin(hook.outer_rack_azim_rad) ];
hook.inner_rad = acos((-hook.offset(1) - hook.width/2) / hook.inner_rad);

% Hook eye cross section
hook.theta = asin(hook.width/2 / hook.eye_rad); % Angular bound for hook eye
rack.angles = linspace(-pi/2 + hook.theta, 3 * pi / 2 - hook.theta, 50)';
hook.eye_xsect = hook.eye_rad * [cos(rack.angles), sin(rack.angles)];

% Hook inner curve cross section
rack.angles = linspace(hook.inner_rad, hook.end_azim_rad, 50)';
hook.inner_curve_xsect = hook.inner_rad * [cos(rack.angles), sin(rack.angles)] + hook.offset;

% Hook outer curve cross section
rack.angles = linspace(hook.end_azim_rad, hook.outer_rack_azim_rad, 50)';
hook.outer_curve_xsect = hook.outer_rad * [cos(rack.angles), sin(rack.angles)] + hook.offset;

% Full hook cross section
hook.xsect = [ hook.eye_xsect; hook.inner_curve_xsect; hook.outer_curve_xsect];


%% Tooth cylinders

rack.co = cos(rack.tooth_angle);
rack.si = sin(rack.tooth_angle);

% Define magnitude of small perturbation to push cylinders into teeth so that they don't show
% outside teeth due to numerical erros in visualization
rack.viz_perturb = 1e-3; % cm

% Length of horizontal tooth cylinders
rack.horiz_tooth_cyl_length = tan(rack.tooth_angle) * (rack.tooth_height - 2 * rack.tooth_cyl_rad);

% Locations of horizontal tooth centers (positive rack side)
rack.horiz_tooth_centers = zeros(rack.num_teeth, 3);
rack.horiz_tooth_centers(:, 1) = rack.center_half_width + rack.horiz_tooth_cyl_length / 2;
rack.horiz_tooth_centers(:, 2) = ...
  (1:1:rack.num_teeth)' * rack.tooth_height + (rack.lower_tooth_margin - rack.tooth_cyl_rad);

% Pertub slightly so that cylindres don't show outside teeth
rack.horiz_tooth_centers = rack.horiz_tooth_centers + rack.viz_perturb * [0 -1 0];

% Length of slant tooth cylinders
rack.slant_tooth_cyl_length = (rack.tooth_height - 2 * rack.tooth_cyl_rad * rack.si) / rack.co;

% Locations of slant tooth centers (positive rack side)
rack.slant_tooth_centers = zeros(rack.num_teeth, 3);
rack.slant_tooth_centers(:, 1) = rack.center_half_width ...
    - rack.tooth_cyl_rad * rack.co + rack.slant_tooth_cyl_length * rack.si / 2;
rack.slant_tooth_centers(:, 2) = (0:1:(rack.num_teeth-1))' * rack.tooth_height ...
    + (rack.lower_tooth_margin ...
       + rack.tooth_cyl_rad * rack.si + rack.slant_tooth_cyl_length * rack.co / 2);
% Pertub slightly so that cylindres don't show outside teeth
rack.slant_tooth_centers = rack.slant_tooth_centers + rack.viz_perturb * [-rack.co +rack.si 0];

% Rotation matrix for slant cylinders.  Follower z -> Base [s c 0]'; Follwer->x -> Base z.
rack.slant_tooth_rotation = [ 0 0 1; rack.co -rack.si 0; rack.si rack.co 0]';


%% Initial conditions

% Distance along tooth slant of climber-sphere contact point
init.s = climber.sphere_rad * (1 + rack.si) / rack.co;

% (x, y) coords of climber-sphere relative to bottom of support tooth
init.x = init.s * rack.si + climber.sphere_rad * rack.co;
init.y = climber.sphere_rad;
% Compute delta x and delta y for initial climber position, and number of full teeth spanned by
% climber in initial configuration
init.delta_x = rack.center_half_width + init.x - traveler.climber_offset;
init.delta_y = sqrt(climber.length^2 - init.delta_x^2);

% Determine which tooth we start on (1-based)
init.gap = rack.lower_tooth_margin - rack.lower_slot_margin; % Gap between slot bottom and first tooth bottom
init.tooth_idx = max(ceil((init.delta_y - init.gap - init.y) / rack.tooth_height), 1);

% Initial position of (horizontal) traveler axle.  This will always be in the range [0, rack.tooth_height].
init.traveler_pos = (init.gap + init.tooth_idx * rack.tooth_height + init.y) - init.delta_y;

% Intial climber angle relative to vertical, in radians
init.climber_angle = atan(init.delta_x / init.delta_y);


