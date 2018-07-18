#!/bin/bash
sudo modprobe pcspkr
beep -f 494 -l 400 -n -f 466 -l 400 -n -f 494 -l 400 -n -f 392 -l 400 -n -f 294 -l 800
sleep 1;

beep -f 466 -l 400 -n -f 440 -l 400 -n -f 466 -l 400 -n -f 392 -l 400 -n -f 294 -l 800

sleep 1;
beep -f 440 -l 400 -n -f 415 -l 400 -n -f 440 -l 400 -n -f 349 -l 400 -n -f 262 -l 1200 
sleep 0.5;
beep -f 440 -l 1200 -n -f 392 -l 1200
