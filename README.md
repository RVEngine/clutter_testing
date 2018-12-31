This repo is a dump of my testing the effect of clutter models in ODOL and MLOD format on AI vision and other clutter related things. In this README I've attempted to document how and what I tested, with the hope that others can play around with it if they wish without much effort on their part.

## Built PBOs
The built PBOs from the testing, and a zip of the mission file can be found [here in the releases](https://github.com/pennyworth12345/clutter_testing/releases). Just note that `pen_clutterDebug_clutterRemoved` will remove the clutter models when the PBO is used, but the properties affected by the clutter, like the AI's vision, should be unaffected.

## Setup
This repository is composed of four folders which hold the main components of the test. These folders were built directly from my P drive (e.g. built from `P:\pen_clutterDebug`, `P:\pen_clutterDebug_models`, etc).
* **pen_clutterDebug** - contains the WRP and source data needed to rebuild the project.
* **pen_clutterDebug_models** - contains the clutter models in ODOL and MLOD form that are used by the pen_clutterDebug terrain.
* **pen_clutterDebug_clutterRemoved** - this is an after the fact config to see what the affects of changing the character of surfaces on an already binarized terrain were.
* **clutterDebug.pen_clutterDebug** - contains the mission file used for basic testing.


#### pen_clutterDebug
This is the directory of the WRP, its textures, and its config. The heightmap used for this test terrain is completely flat. The sat and mask image are the exact same and extremely simple, as they're composed by single colors. The ground textures used also matched both the mask and sat colors. The mask and sat are shown below. The colors from the image are as follows:
* Red - the normal sized clutter model that was packed from an ODOL.
* Blue - the normal sized clutter model that was packed from an MLOD.
* Green - the large clutter model that was packed from an ODOL.
* Yellow - the large clutter model that was packed from an MLOD.
* Grey - surface with no clutter.

![Mask and sat images](https://i.imgur.com/l3n2Wbs.png)

#### pen_clutterDebug_models
Within this folder are the four P3Ds used as clutter by the config `pen_clutterDebug\config.cpp`. The models all share the same texture and RVMAT. The first and most important difference between these models is indicated by the `large` tag. The models denoted by `large` are the exact same as the ones without a tag, with the exception of a single vertex added in the resolution LODs. This was done with the goal of "inflating" the model's boundbox size, and therefore the game thinking the model is bigger than it actually is. An example of how that looked in Object Builder is shown below. The second difference between the models is what format they're in for packing. The options being ODOL (binarized) or MLOD (unbinarized).

![Large model OB view](https://i.imgur.com/yraDKT3.png)

#### pen_clutterDebug_clutterRemoved
This is a simple config that was added after the initial testing to see what effects of clutter could be removed by setting the surfaces character to empty. As expected, it uses `requiredAddons` to load after the main terrain config from `pen_clutterDebug\config.cpp`.

#### clutterDebug.pen_clutterDebug
This is a test mission I created to investigate some of the effects of the clutter, mainly the effect on the AI's vision. An image showing what you'll see is shown below.

![Test mission view](https://i.imgur.com/Sx223yW.jpg)

Each unit within 100 meters of you will have three values above their head, separated by commas. The first number shown is the result of the [checkVisibility](https://community.bistudio.com/wiki/checkVisibility) command using the eye position of your player and the other unit's eye position. The number shown will be in a range of 0 - 1, where 1 is full visbility of the unit. The second value is the distance from your player to the other unit. The third value is the name of the surface the unit is standing on. The result from `checkVisibility` is useful because it's a fairly accurate representation of how well the AI would be able to see you from that location. There are units in each of the four clutter areas directly around the center piece, as well as a group of three further into each of the four clutter areas. Those units were placed deep within their clutter area because the visibility of a unit where two clutter areas met was affected by which area was adjacent.

In both the blue and red areas its expected that the visibility returned will be 1 while both characters are standing up. The visibility will drop below 1 when crouched or prone, based on the distance from the unit. For the green and yellow areas, the visibility should be 0 up until you're extremely close to the other unit. Visibilities on the edges of the clutter areas however can be inconsistent and hard to predict.

## Conclusions
The initial goal of this investigation was to see if the format of a model used for clutter had any effect on the produced WRP. However, it appears the model format **has no effect**. With that being said, the testing showed that **increasing the clutter model's size did in fact affect the AI's ability to see other units when they were on that surface**. In the event that the clutter was very large (~2 meters+), it could cause the AI to be unable to see the enemy until they were within a few meters of each other. This effect was "baked" into the WRP, such that even if you were to remove the clutter using the same method as used in `pen_clutterDebug_clutterRemoved`, the AI's vision would remain the same as if the clutter was there.

When using Mikero's Eliteness tool it's possible to see the "clutter mask" of a terrain. During this testing I periodically checked the appearance of the clutter mask within the tool, and observed that changing the probability of one or more of the surface's CfgSurfaceCharacters entries caused the binarized terrain's clutter mask to change. The areas using the larger clutter also appeared differently than those with the normal sized clutter on the clutter mask within Eliteness. An example of that is shown below. At the time of writing this I'm not aware of how exactly and by what amount these things changes the terrain's clutter mask, but it's something I might look into more in the future.

![Test mission view](https://i.imgur.com/tgPC42M.png)
