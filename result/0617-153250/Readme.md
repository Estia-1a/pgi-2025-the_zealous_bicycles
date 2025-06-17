# Daily Evaluation 17/06 - 15:32:50
You can find below how you did for each feature. 
 You should merge the pull request to keep the eval and automatically close and open the issues you have finished!
# Milestone  Tutorial
Score : 4/23 :  17%
## Detail by Feature
| Feature     | Score       | Missed tests                                                                                                                                                                                              | Stdout                            |
| :---------- | :---------- | :-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :-------------------------------- |
| dimension   | 4/4 :  100% |                                                                                                                                                                                                           |                                   |
| first_pixel | 0/5 :  0%   | First Pixel 64x64 : 255,0,0<br>First Pixel Red : 255,0,0<br>First Pixel Green : 0,255,0<br>First Pixel Blue : 0,0,255<br>First Pixel 1 2 3 : 1,2,3                                                        | 255, 0, 0<br>255, 0, 0<br>0, 255… |
| tenth_pixel | 0/5 :  0%   | Tenth Pixel 64x64 : 255,0,0<br>Tenth Pixel Red : 255,0,0<br>Tenth Pixel Green : 0,255,0<br>Tenth Pixel Blue : 0,0,255<br>Tenth Pixel 11 12 13 : 1,2,3                                                     | 255, 0, 0<br>255, 0, 0<br>0, 255… |
| second_line | 0/5 :  0%   | Second line First Pixel 64x64 : 255,0,0<br>Second line First Pixel Red : 255,0,0<br>Second line First Pixel Green : 0,255,0<br>Second line First Pixel Blue : 0,0,255<br>Second line First Pixel 21 22 23 | 255, 0, 0<br>255, 0, 0<br>0, 255… |
| print_pixel | 0/4 :  0%   | Print Pixel (0,0) : 0,0,0<br>Print Pixel (2,3) : 20,30,26<br>Print Pixel (3,2) : 30,20,19<br>Print Pixel (7,7) : 0,0,0                                                                                    | 0, 0, 0<br>20, 30, 26<br>30, 20,… |

# Milestone  statistiques
Score : 0/26 :  0%
## Detail by Feature
| Feature         | Score     | Missed tests                                                                          | Stdout                            |
| :-------------- | :-------- | :------------------------------------------------------------------------------------ | :-------------------------------- |
| max_pixel       | 0/4 :  0% | Max Pixel black 8x8<br>Max Pixel white 8x8<br>Max Pixel at 6 5<br>Max Pixel at 3 4    | (0, 0) : 0, 0, 0<br>(0, 0) : 255… |
| min_pixel       | 0/4 :  0% | Min Pixel black 8x8<br>Min Pixel white 8x8<br>Min Pixel at 6 5<br>Min Pixel at 3 4    | (0, 0) : 0, 0, 0<br>(0, 0) : 255… |
| min_component R | 0/3 :  0% | Min Component R of black 8x8<br>Min Component R of white 8x8<br>Min Component 2 0 5   | (0, 0) : 0<br>(0, 0) : 255<br>(2… |
| min_component G | 0/3 :  0% | Min Component G of black 8x8<br>Min Component G of white 8x8<br>Min Component 2 0 5   | (0, 0) : 0<br>(0, 0) : 255<br>(2… |
| min_component B | 0/3 :  0% | Min Component B of black 8x8<br>Min Component B of white 8x8<br>Min Component 2 0 5   | (0, 0) : 0<br>(0, 0) : 255<br>(2… |
| max_component R | 0/3 :  0% | Max Component R of black 8x8<br>Max Component R of white 8x8<br>Max Component 2 0 255 | (0, 0) : 0<br>(0, 0) : 255<br>(2… |
| max_component G | 0/3 :  0% | Max Component G of black 8x8<br>Max Component G of white 8x8<br>Max Component 2 0 255 | (0, 0) : 0<br>(0, 0) : 255<br>(2… |
| max_component B | 0/3 :  0% | Max Component B of black 8x8<br>Max Component B of white 8x8<br>Max Component 2 0 255 | (0, 0) : 0<br>(0, 0) : 255<br>(2… |

# Milestone  colors
Score : 24.779999999999998/35 :  70%
## Detail by Feature
| Feature              | Score                      | Missed tests                                                                                                                                         | Stdout           |
| :------------------- | :------------------------- | :--------------------------------------------------------------------------------------------------------------------------------------------------- | :--------------- |
| color_red            | 5/5 :  100%                |                                                                                                                                                      |                  |
| color_blue           | 5/5 :  100%                |                                                                                                                                                      |                  |
| color_green          | 5/5 :  100%                |                                                                                                                                                      |                  |
| color_gray           | 5/5 :  100%                |                                                                                                                                                      |                  |
| color_invert         | 0/5 :  0%                  | Invert red image<br>Invert blue image<br>Invert green Image<br>Invert white Image<br>Invert black Image                                              | <br><br><br><br> |
| color_gray_luminance | 4.779999999999999/5 :  95% |                                                                                                                                                      |                  |
| color_desaturate     | 0/5 :  0%                  | Convert red image to GRAY<br>Convert blue image to GRAY<br>Convert green Image to GRAY<br>Convert white Image to GRAY<br>convert black Image to GRAY | <br><br><br><br> |

# Milestone  transform
Score : 0/15 :  0%
## Detail by Feature
| Feature           | Score     | Missed tests                                                   | Stdout   |
| :---------------- | :-------- | :------------------------------------------------------------- | :------- |
| rotate_cw         | 0/3 :  0% | rotate square image<br>rotate large image<br>rotate high image | <br><br> |
| rotate_acw        | 0/3 :  0% | rotate square image<br>rotate large image<br>rotate high image | <br><br> |
| mirror_horizontal | 0/3 :  0% | mirror square image<br>mirror large image<br>mirror high image | <br><br> |
| mirror_vertical   | 0/3 :  0% | mirror square image<br>mirror large image<br>mirror high image | <br><br> |
| mirror_total      | 0/3 :  0% | mirror square image<br>mirror large image<br>mirror high image | <br><br> |

# Milestone  resize
Score : 0/60 :  0%
## Detail by Feature
| Feature        | Score      | Missed tests                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           | Stdout                            |
| :------------- | :--------- | :----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :-------------------------------- |
| scale_nearest  | 0/20 :  0% | scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3                                                                                 | <br><br><br><br><br><br><br><br>… |
| scale_bilinear | 0/20 :  0% | scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12<br>scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12<br>scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12<br>scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12<br>scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12                               | <br><br><br><br><br><br><br><br>… |
| scale_crop     | 0/20 :  0% | scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10 | <br><br><br><br><br><br><br><br>… |

