// Copyright (C) Peter Ivanov <ivanovp@gmail.com>, 2023
// License: Attribution-NonCommercial-ShareAlike (CC BY-NC-SA)

/* 1: Render top of case */
enable_top = 1;
/* 1: Render bottom of case */
enable_bottom = 0;

case_height = 20;
keybody_width = 14;
keybody_length = 14;
keybody_height = 8;
thickness = 1.3;
/* Number of keys */
key_num = 7;
key_space_x = 6;
key_space_x_left = 3;
key_space_x_right = 3;
key_space_y = 6;
cylinder_outer_diameter = 6.4;
cylinder_inner_diameter = 2.9;
/* 4 drill's diameter to fasten bottom part to the top */
drill_diameter = 3.4;
/* Cutout for USB cable */
cutout_width = 10;
cutout_height = 8;

/* Internal variables */
delta = 0.1;
w = keybody_width + key_space_x;
fw = w * key_num + key_space_x + key_space_x_left + key_space_x_right;
epsilon = 0.1;
$fn = 64;
echo("Internal width: ", keybody_length + key_space_y * 2 - thickness * 2);

module cyl()
{
    color("lightblue") difference()
    {
        cylinder(h=case_height - thickness, d=cylinder_outer_diameter);
        translate([0, 0, -epsilon]) cylinder(h=case_height - thickness + epsilon * 2, d=cylinder_inner_diameter);
    }
}

module cyl2()
{
    translate([0, 0, -epsilon]) cylinder(h=case_height - thickness + epsilon * 2, d=drill_diameter);
}

if (enable_top)
{
    translate([cylinder_outer_diameter / 2, cylinder_outer_diameter / 2, thickness]) cyl();
    translate([fw - cylinder_outer_diameter / 2, cylinder_outer_diameter / 2, thickness]) cyl();
    translate([cylinder_outer_diameter / 2, keybody_length + key_space_y * 2 - cylinder_outer_diameter / 2, thickness]) cyl();
    translate([fw - cylinder_outer_diameter / 2, keybody_length + key_space_y * 2 - cylinder_outer_diameter / 2, thickness]) cyl();

    color("lightblue") difference()
    {
        cube([fw, keybody_length + key_space_y * 2, case_height]);
        translate([thickness, thickness, -epsilon]) cube([fw - thickness * 2, keybody_length + key_space_y * 2 - thickness * 2, case_height - thickness + epsilon]);
        for (i = [0 : key_num - 1])
        {
            translate([key_space_x_left + i * w + key_space_x, key_space_y, case_height - keybody_height / 2]) cube([keybody_width, keybody_length, keybody_height]);
        }
        translate([-epsilon, keybody_length / 2 + key_space_y - cutout_width / 2, thickness]) cube([thickness + epsilon * 2, cutout_width, cutout_height]);
    }
}

if (enable_bottom)
{
    translate([0, 0, -thickness]) difference()
    {
        union()
        {
            cube([fw, keybody_length + key_space_y * 2, thickness]);
            translate([thickness + delta, thickness + delta, thickness]) cube([fw - thickness * 2 - delta * 2, keybody_length + key_space_y * 2 - thickness * 2 - delta * 2, thickness - delta * 2]);    
        }
        translate([cylinder_outer_diameter / 2, cylinder_outer_diameter / 2, 0]) cyl2();
        translate([fw - cylinder_outer_diameter / 2, cylinder_outer_diameter / 2, 0]) cyl2();
        translate([cylinder_outer_diameter / 2, keybody_length + key_space_y * 2 - cylinder_outer_diameter / 2, 0]) cyl2();
        translate([fw - cylinder_outer_diameter / 2, keybody_length + key_space_y * 2 - cylinder_outer_diameter / 2, 0]) cyl2();       
    }
}
