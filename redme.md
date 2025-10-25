// PoVRay 3.7 Scene File " ... .pov"
// author:  Rafa³ Curzyd³o
// date:    12-10-2025
//------------------------------------------------------------------------
#version 3.7;
global_settings{ assumed_gamma 1.0 }
#default{ finish{ ambient 0.1 diffuse 0.9 }} 
//------------------------------------------------------------------------
#include "colors.inc"
#include "textures.inc"
#include "glass.inc"
#include "metals.inc"
#include "golds.inc"
#include "stones.inc"
#include "woods.inc"
#include "shapes.inc"
#include "shapes2.inc"
#include "functions.inc"
#include "math.inc"
#include "transforms.inc"
//------------------------------------------------------------------------
#declare Camera_0 = camera {/*ultra_wide_angle*/ angle 15      // front view
                            location  <0.0 , 1.0 ,-40.0>
                            right     x*image_width/image_height
                            look_at   <0.0 , 1.0 , 0.0>}
#declare Camera_1 = camera {/*ultra_wide_angle*/ angle 14   // diagonal view
                            location  <220.0 , 215.0 ,-220.0>
                            right     x*image_width/image_height
                            look_at   <0.0 , 1 , 0.0>}
#declare Camera_2 = camera {/*ultra_wide_angle*/ angle 90  //right side view
                            location  <3.0 , 1.0 , 0.0>
                            right     x*image_width/image_height
                            look_at   <0.0 , 1.0 , 0.0>}
#declare Camera_3 = camera {/*ultra_wide_angle*/ angle 90        // top view
                            location  <0.0 , 3.0 ,-0.001>
                            right     x*image_width/image_height
                            look_at   <0.0 , 1.0 , 0.0>}
camera{Camera_1}
//------------------------------------------------------------------------
// sun -------------------------------------------------------------------
light_source{<1500,2500,-2500> color White}
// sky -------------------------------------------------------------------
sky_sphere{ pigment{ gradient <0,1,0>
                     color_map{ [0   color rgb<1,1,1>         ]//White
                                [0.4 color rgb<0.14,0.14,0.56>]//~Navy
                                [0.6 color rgb<0.14,0.14,0.56>]//~Navy
                                [1.0 color rgb<1,1,1>         ]//White
                              }
                     scale 2 }
           } // end of sky_sphere 
//------------------------------------------------------------------------

//------------------------------ the Axes --------------------------------
//------------------------------------------------------------------------
#macro Axis_( AxisLen, Dark_Texture,Light_Texture) 
 union{
    cylinder { <0,-AxisLen,0>,<0,AxisLen,0>,0.05
               texture{checker texture{Dark_Texture } 
                               texture{Light_Texture}
                       translate<0.1,0,0.1>}
             }
    cone{<0,AxisLen,0>,0.2,<0,AxisLen+0.7,0>,0
          texture{Dark_Texture}
         }
     } // end of union                   
#end // of macro "Axis()"
//------------------------------------------------------------------------
#macro AxisXYZ( AxisLenX, AxisLenY, AxisLenZ, Tex_Dark, Tex_Light)
#end// of macro "AxisXYZ( ... )"
//------------------------------------------------------------------------

#declare Texture_A_Dark  = texture {
                               pigment{ color rgb<1,0.45,0>}
                               finish { phong 1}
                             }
#declare Texture_A_Light = texture { 
                               pigment{ color rgb<1,1,1>}
                               finish { phong 1}
                             }


// ground -----------------------------------------------------------------
//---------------------------------<<< settings of squared plane dimensions
#declare RasterScale = 1.0;
#declare RasterHalfLine  = 0.035;  
#declare RasterHalfLineZ = 0.035; 
//-------------------------------------------------------------------------
#macro Raster(RScale, HLine) 
       pigment{ gradient x scale RScale
                color_map{[0.000   color rgbt<1,1,1,0>*0.6]
                          [0+HLine color rgbt<1,1,1,0>*0.6]
                          [0+HLine color rgbt<1,1,1,1>]
                          [1-HLine color rgbt<1,1,1,1>]
                          [1-HLine color rgbt<1,1,1,0>*0.6]
                          [1.000   color rgbt<1,1,1,0>*0.6]} }
 #end// of Raster(RScale, HLine)-macro    
//-------------------------------------------------------------------------
    

plane { <0,1,0>, 0    // plane with layered textures
        texture { pigment{color White*1.1}
                  finish {ambient 0.45 diffuse 0.85}}
        texture { Raster(RasterScale,RasterHalfLine ) rotate<0,0,0> }
        texture { Raster(RasterScale,RasterHalfLineZ) rotate<0,90,0>}
        rotate<0,0,0>
      }
//------------------------------------------------ end of squared plane XZ

//--------------------------------------------------------------------------
//---------------------------- objects in scene ----------------------------
//--------------------------------------------------------------------------
                                                                                           
                                      
                                      

difference {



union {
                                     
                                      
difference {                                                                                           
cylinder { <0,0,0>,<0,13,0>, 44/2 

           texture { pigment { color Green }
                   //normal  { bumps 0.5 scale <0.005,0.25,0.005>}
                     finish  { phong 0.5 reflection{ 0.00 metallic 0.00} } 
                   } // end of texture

           scale <1,1,1> rotate<0,0,0> translate<0,0,0>
         } // end of cylinder -------------------------------------          
 }
         
cylinder { <0,0,0>,<0,10,0>, 12/2 

           texture { pigment { color Blue }
                   //normal  { bumps 0.5 scale <0.005,0.25,0.005>}
                     finish  { phong 0.5 reflection{ 0.00 metallic 0.00} } 
                   } // end of texture

           scale <1,1,1> rotate<0,0,0> translate<0,13,0>
         } // end of cylinder -------------------------------------
                                                                                           


}       //end union     

cylinder { <0,0,0>,<0,24,0>, 6/2

           texture { pigment { color Pink }
                   //normal  { bumps 0.5 scale <0.005,0.25,0.005>}
                     finish  { phong 0.5 reflection{ 0.00 metallic 0.00} } 
                   } // end of texture

           scale <1,1,1> rotate<0,0,0> translate<0,0,0>
         } // end of cylinder -------------------------------------             
         
 cylinder { <-1,0,0>,<7,0,0>, 3/2
           texture { pigment { color rgb<1,1,1>}
                   //normal  { bumps 0.5 scale <0.25, 0.005,0.005>}  
                     finish  { phong 0.5 reflection{ 0.00 metallic 0.00} } 
                   } // end of texture
           scale <1,1,1> rotate<0,0,0> translate<0,17,0>
         } // end of cylinder  ------------------------------------
                                            
difference {


                          

cone{ <0,0,0>,33/2,<0,2.5,0>,38/2 

      texture{ pigment{ color Orange}
               // pigment{ color rgb<1.00,0.60,0.00>}
               finish { phong 0.5 reflection{ 0.00 metallic 0.00} } 
             } // end of texture
      scale <1,1,1> rotate<0,0,0> translate<0,10.8,0> 
    } // end of cone -----------------------------------            
    
    cone{ <0,2.5,0>,11.5/2,<0,0,0>,17/2 

      texture{ pigment{ color Orange}
               // pigment{ color rgb<1.00,0.60,0.00>}
               finish { phong 0.5 reflection{ 0.00 metallic 0.00} } 
             } // end of texture
      scale <1,1,1> rotate<0,0,0> translate<0,10.8,0> 
    } // end of cone -----------------------------------

    
    
    
}    //end difference           


difference {


                          

cone{ <0,0,0>,33/2,<0,2.5,0>,38/2 

      texture{ pigment{ color Orange}
               // pigment{ color rgb<1.00,0.60,0.00>}
               finish { phong 0.5 reflection{ 0.00 metallic 0.00} } 
             } // end of texture
      scale <1,1,1> rotate<180,0,0> translate<0,2.4,0> 
    } // end of cone -----------------------------------            
    
    cone{ <0,2.5,0>,11.5/2,<0,0,0>,17/2 

      texture{ pigment{ color Orange}
               // pigment{ color rgb<1.00,0.60,0.00>}
               finish { phong 0.5 reflection{ 0.00 metallic 0.00} } 
             } // end of texture
      scale <1,1,1> rotate<180,0,0> translate<0,2.5,0> 
    } // end of cone -----------------------------------

    
    
    
}    //end difference    
                                 

         
box { <0,0,0>,< 50, 50, 50>   

      texture { pigment{ color rgb<1.00, 1.00, 1.00>*1.1}  
                finish { phong 1 reflection{ 0.00 metallic 0.00} } 
              } // end of texture

      scale <1,1,1> rotate<0,90,0> translate<0,0,0> 
    } // end of box --------------------------------------
                                        
#declare Ball = 
 cylinder { <0,0,0>,<0,40,0>, 7/2 

           texture { pigment { color Red }
                   //normal  { bumps 0.5 scale <0.005,0.25,0.005>}
                     finish  { phong 0.5 reflection{ 0.00 metallic 0.00} } 
                   } // end of texture

           scale <1,1,1> rotate<0,0,0> translate<0,0,12.5>
} //----------------------------------------------------

union{ //------------------------------------------------------
 #local Nr = 0;     // start
 #local EndNr = 8; // end
 #while (Nr< EndNr) 
   object{ Ball translate<1,0.25,0> rotate<0,Nr * 360/EndNr,0>} 

 #local Nr = Nr + 1;    // next Nr
 #end // ---------------  end of loop 

rotate<0,0,0>
translate<0,0,0>
} // end of union ---------------------------------------------        



// CSG difference, subtract intersections of shapes 2...N from Shape1
difference {      
cone{ <0,0,0>,45/2,<0,1,0>,47/2 

      texture{ pigment{ color rgbf<1.00,1,1,0.75>}
               // pigment{ color rgb<1.00,0.60,0.00>}
               finish { phong 0.5 reflection{ 0.00 metallic 0.00} } 
             } // end of texture
      scale <1,1,1> rotate<0,0,0> translate<0,0.0001,0> 
    } // end of cone -----------------------------------
cone{ <0,0,0>,43/2,<0,1,0>,44/2 

      texture{ pigment{ color rgbf<1.00,1,1,0.75>}
               // pigment{ color rgb<1.00,0.60,0.00>}
               finish { phong 0.5 reflection{ 0.00 metallic 0.00} } 
             } // end of texture
      scale <1,1,1> rotate<0,0,0> translate<0,0.0001,0> 
    } // end of cone -----------------------------------





}     //end diference 

difference {

cone{ <0,0,0>,45/2,<0,1,0>,47/2 

      texture{ pigment{ color Pink}
               // pigment{ color rgb<1.00,0.60,0.00>}
               finish { phong 0.5 reflection{ 0.00 metallic 0.00} } 
             } // end of texture
      scale <1,1,1> rotate<180,0,0> translate<0,13.1,0> 
    } // end of cone -----------------------------------

cone{ <0,0,0>,43/2,<0,1,0>,44/2

      texture{ pigment{ color Yellow}
               // pigment{ color rgb<1.00,0.60,0.00>}
               finish { phong 0.5 reflection{ 0.00 metallic 0.00} } 
             } // end of texture
      scale <1,1,1> rotate<180,0,0> translate<0,13.1,0> 




}     //end diference



                                                                                     
                                            
                                            
         
}       //end difference                         
         
                  


  
} // end of cone -----------------------------------           
    
    
    
