#!/usr/bin/python3
# -*- coding: utf-8 -*-

while True:
    try:
        n, my_id = map(int, input().split())
        cs_videos = 0

        for i in range(n):
            user_id, game_type = map(int, input().split())
            if (user_id == my_id):
                if game_type == 0: cs_videos += 1

        print(cs_videos)
    except:
        break
