# GPredict

These are my Mods on the excellent GPredict satellite tracking. 


There are 4 features, each one in it's own seperate branch. So it is up to you if you would like all or none of them.

You should be aware that this is not the official, version of gpredict; It is just a few extra things that I wanted.


## toggle_radio

The toggle_radio branch, allows my IC7000 which is not a dedicated SAT rig, to almost behave correctly. I believe that there was some missing configuration in the original code, which I think I have corrected. 

Additionally - depending on the selected SAT some extra rigcontrol commands are sent to the Radio.

At the moment these are limited to MODE Switches, but it is not consistent, and should be improved further.
I believe that the data from SATNOGS would be most appropiate here.


## colorbuttons

I find some of the screens, (Rig Control especially) very dull - so I spiced them up a little, using a custom CSS file.
You are free to change these colors and values to what you want. If you remove them, then the existing color schemes will apply.

The file to move into your $HOME/.config/Gpredict is found in *src/
