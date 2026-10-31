#include "raylib.h"
#include<math.h>

 
Sound pong=LoadSound("bounce.wav");
Sound gameOver=LoadSound("gameOver.wav");


void PlayBounceSound()
{
    PlaySound(pong);    
}

int main()
{
    
    // --- Initialisation ---
InitWindow(800,800,"Phantom Bounce Game");
InitAudioDevice();
SetTraceLogLevel(LOG_NONE);
Texture2D background= LoadTexture("gamebgv1.png");
Music music1=LoadMusicStream("Lazerhawk.mp3");
Music music2=LoadMusicStream("Stereo Madness.mp3");
Music music3=LoadMusicStream("purple_motions.xm");
PlayMusicStream(music1);
SetMusicVolume(music2,0.15);
double theta,i=0.0;
int l=0;
double ballradius1=20.0;
double ballxp1=400.0,ballyp1=200.0;
double ballvx1=2.5,ballvy1=2.0;
double ballradius2=20.0;
double ballxp2=400.0,ballyp2=600.0;
double ballvx2=2.0,ballvy2=1.5;
double ballradius3=20.0;
double ballxp3=200.0,ballyp3=200.0;
double ballvx3=2.0,ballvy3=1.5;
double ballradius4=20.0;
double ballxp4=200.0,ballyp4=600.0;
double ballvx4=2.5,ballvy4=2.0;
double ballvxtmp=0.0,ballvytmp=0.0;
double paddleyp=400.0,paddlexp=300.0;
int Score=0,HighScore=0;
int alphaB=0,alphaR=0;
int alphaText1=255,alphaText2=255,alphaText3=255;
int alphaBG=0;
long FrameCount=0;
double ballxptmp,ballyptmp;
SetTargetFPS(120);

   //   *** Title Screen ***
 while(!(IsKeyDown(KEY_ENTER) || WindowShouldClose()))
    {   
        UpdateMusicStream(music1);
        theta+=0.03;      
        BeginDrawing();
        ClearBackground(Color{215,195,210,255});
        DrawText("PHANTOM",140,100+50*sin((theta)*0.6),100,Color{0,121,241,i});
        DrawText("BOUNCE",170,300+50*cos((theta)*0.5),100,Color{230,41,55, 255-i});
        DrawText("Press ENTER to start",145,550,40,BLACK);
        DrawText("Press H For HELP",175,650,40,LIME);
        EndDrawing();
        if(IsKeyDown(KEY_H))
            while(!(IsKeyDown(KEY_M) || WindowShouldClose()))
        {
            BeginDrawing();
            ClearBackground(Color{215,216,245,255});
            DrawText("HOW TO PLAY",150,40,60,Color{20,100,30,255});
            if(IsKeyDown(KEY_LEFT) && l<=40) l+=3;
            if(IsKeyDown(KEY_RIGHT) && l>=-700) l-=3;
            DrawText("Use the Left and Right arrow keys to move.",25+l,120,30,BLACK);            
            DrawText("Your Goal is to ensure the red ball hits the red wall and the blue ball hits the blue wall.",25+l,160,30,BLACK);
            DrawText("Ghost balls do not interact with the paddle or other balls and do not contribute to scores.",25+l,200,30,BLACK);
            DrawText("Ghost balls produce no sound on collision with walls.",25+l,240,30,BLACK);
            DrawText("Ghost balls, transparent at first gradually turn opaque till they look same as the real balls.",25+l,280,30,BLACK);
            DrawText("Ghost balls can teleport and swap positions with real balls.",25+l,320,30,BLACK);
            DrawText("Later in the game even ghost balls produce sound on collisions.",25+l,360,30,BLACK);
            DrawText("Beware of the Phantom Camouflage which makes it difficult to identify balls.",25+l,400,30,BLACK);
            DrawText("Press P to pause the game and R to return back.",25+l,440,30,BLACK);
            DrawText("Press M to return to Main Menu",50,700,40,RED);
            EndDrawing();  
        }    
        i++;
        if(i>=255) i=0;
    }
    if(IsKeyDown(KEY_ENTER)) { StopMusicStream(music1); _sleep(500); PlayMusicStream(music2);}


      //******* Main Game loop *******
      
  while(!WindowShouldClose())
  {
      if(Score>HighScore) HighScore=Score;
       FrameCount++;
       UpdateMusicStream(music2);
       
      // *** Ball 1 movement ***
    ballxp1 += ballvx1;
    ballyp1 += ballvy1;   
    if (ballxp1 >= 800 - ballradius1) {
        ballxp1 = 800 - ballradius1;
        ballvx1 *= -1.0f;
        PlayBounceSound();
    } else if (ballxp1 <= ballradius1) {
        ballxp1 = ballradius1;
        ballvx1 *= -1.0f;
        PlayBounceSound();
    }

    if (ballyp1 >= 800 - ballradius1) {
        ballyp1 = 800 - ballradius1;
        ballvy1 *= -1.0f;
        PlaySound(gameOver);
        StopMusicStream(music2);
        
         while(!(IsKeyDown(KEY_ENTER) || WindowShouldClose()))
        {
            BeginDrawing();
            ClearBackground(BLACK);
            DrawText("GAME OVER",180,400,70,BLUE);
            DrawText(TextFormat("Score: %i", Score), 280, 500, 40, WHITE);
            DrawText("Press ENTER",260,600,30,RAYWHITE);
            EndDrawing();
        }
        PlayMusicStream(music2);
        Score=0;
        alphaB=0,alphaR=0;
        alphaText1=255,alphaText2=255,alphaText3=255;
        ballxp1=400.0,ballyp1=200.0;
        ballvx1=2.5,ballvy1=2.0;
        ballxp2=400.0,ballyp2=600.0;
        ballvx2=2.0,ballvy2=1.5;
        paddlexp=300.0;
        FrameCount=0;
     
    }  else if (ballyp1 <= ballradius1) {
        ballyp1 = ballradius1;
        ballvy1 *= -1.0f;
        ballvx1 *= 1.0f;
        PlayBounceSound();
        Score++;
    }
    
    // *** Ball 2 movement ***
    ballxp2 += ballvx2;
    ballyp2 += ballvy2;

    if (ballxp2 >= 800 - ballradius2) {
        ballxp2 = 800 - ballradius2;
        ballvx2 *= -1.0f;
        PlayBounceSound();
    
    } else if (ballxp2 <= ballradius2) {
        ballxp2 = ballradius2;
        ballvx2 *= -1.0f;
        PlayBounceSound();
    }

    if (ballyp2 >= 800 - ballradius2) {
        ballyp2 = 800 - ballradius2;
        ballvy2 *= -1.0f;
        ballvx2 *= 1.0f;
        PlayBounceSound();
        Score++;
    } else if (ballyp2 <= ballradius2) {
        ballyp2 = ballradius2;
        ballvy2 *= -1.0f;
        PlaySound(gameOver);
        StopMusicStream(music2);
        
        while(!(IsKeyDown(KEY_ENTER) || WindowShouldClose()))
        {
            BeginDrawing();
            ClearBackground(BLACK);
            DrawText("GAME OVER",180,400,70,RED);
            DrawText(TextFormat("Score: %i", Score), 280, 500, 40, WHITE);
            DrawText("Press ENTER",260,600,30,RAYWHITE);
            EndDrawing();
        }
        PlayMusicStream(music2);
        Score=0;
        alphaB=0,alphaR=0;
        alphaText1=255,alphaText2=255,alphaText3=255;
        ballxp1=400.0;ballyp1=200.0;
        ballvx1=2.5;ballvy1=2.0;
        ballxp2=400.0;ballyp2=600.0;
        ballvx2=2.0;ballvy2=1.5;
        paddlexp=300.0;
        FrameCount=0;
         }
         
            // *** Ball 3 movement ***
    ballxp3 += ballvx3;
    ballyp3 += ballvy3;
       
    if (ballxp3 >= 800 - ballradius3) {
        ballxp3 = 800 - ballradius3;
        ballvx3 *= -1.0f;
      if(Score>250) PlayBounceSound();
    } else if (ballxp3 <= ballradius3) {
        ballxp3 = ballradius3;
        ballvx3 *= -1.0f;
      if(Score>250) PlayBounceSound();
    }

    if (ballyp3 >= 800 - ballradius3) {
        ballyp3 = 800 - ballradius3;
        ballvy3 *= -1.0f;
       if(Score>250) PlayBounceSound();
    }  
     else if (ballyp3 <= ballradius3) {
        ballyp3 = ballradius3;
        ballvy3 *= -1.0f;
       if(Score>250) PlayBounceSound();
     }
     
                // *** Ball 4 movement ***
    ballxp4 += ballvx4;
    ballyp4 += ballvy4;
       
    if (ballxp4 >= 800 - ballradius4) {
        ballxp4 = 800 - ballradius4;
        ballvx4 *= -1.0f;
      if(Score>250)  PlayBounceSound();
    } else if (ballxp4 <= ballradius4) {
        ballxp4 = ballradius4;
        ballvx4 *= -1.0f;
       if(Score>250) PlayBounceSound();
    }

    if (ballyp4 >= 800 - ballradius4) {
        ballyp4 = 800 - ballradius4;
        ballvy4 *= -1.0f;
       if(Score>250) PlayBounceSound();
    }  
     else if (ballyp4 <= ballradius4) {
        ballyp4 = ballradius4;
        ballvy4 *= -1.0f;
       if(Score>250) PlayBounceSound();
     }
 
               //        *** Ball 1 Paddle collision ***
     if(ballxp1>=paddlexp-ballradius1 && ballxp1<=(paddlexp+500+ballradius1) && ballyp1>=paddleyp-ballradius1 && ballyp1<=(paddleyp+30+ballradius1))
   
     { 
     if(!(ballxp1>=paddlexp-ballradius1 && ballxp1<=paddlexp-ballradius1+15 || ballxp1>=(paddlexp+500+ballradius1-15) && ballxp1<=(paddlexp+500+ballradius1)))
        ballvy1*=-1.0f;
        PlayBounceSound();
        
        if(ballxp1>=paddlexp-ballradius1 && ballxp1<=paddlexp-ballradius1+15 || ballxp1>=(paddlexp+500+ballradius1-15) && ballxp1<=(paddlexp+500+ballradius1))
        {
            ballyp1=ballyp1-50;
            ballvy1*=-1.0f;
            
        }
      }

         
                //        *** Ball 2 Paddle collision ***   
    if(ballxp2>=paddlexp-ballradius2 && ballxp2<=(paddlexp+500+ballradius2) && ballyp2>=paddleyp-ballradius2 && ballyp2<=(paddleyp+30+ballradius2))
   
     { 
     if(!(ballxp2>=paddlexp-ballradius2 && ballxp2<=paddlexp-ballradius2+15 || ballxp2>=(paddlexp+500+ballradius2-15) && ballxp2<=(paddlexp+500+ballradius2)))
        ballvy2*=-1.0f;
        PlayBounceSound();
        
        if(ballxp2>=paddlexp-ballradius2 && ballxp2<=paddlexp-ballradius2+15 || ballxp2>=(paddlexp+500+ballradius2-15) && ballxp2<=(paddlexp+500+ballradius2))
        {
            ballyp2=ballyp2+50;
            ballvy2*=-1.0f;
            
        }
      }
  
      // *** Ball-Ball collision ***
      double distance=sqrt(pow((ballxp2-ballxp1),2.0)+pow((ballyp2-ballyp1),2.0));
      if(distance<=(ballradius1+ballradius2))
      {
          ballvxtmp=ballvx1;
          ballvx1=ballvx2;
          ballvx2=ballvxtmp;
          ballvytmp=ballvy1;
          ballvy1=ballvy2;
          ballvy2=ballvytmp;
          PlayBounceSound();          
      }
      
      // *** Paddle Movement ***
      if(IsKeyDown(KEY_LEFT))
      {
          paddlexp-=4.0;
       if(paddlexp<=0.0) paddlexp=0.0;
      }  
      
          if(IsKeyDown(KEY_RIGHT))
      {
          paddlexp+=4.0;
       if(paddlexp>=300) paddlexp=300.0;
      }  
    
      // *** Teleport(Identity Swap) ***
      if(Score>=25 && FrameCount%600==0 && ballyp3<=300) 
      {
          ballxptmp=ballxp1;
          ballxp1=ballxp3;
          ballxp3=ballxptmp;
          ballyptmp=ballyp1;
          ballyp1=ballyp3;
          ballyp3=ballyptmp;    
      }
      if(Score>=75 && FrameCount%600==0 && ballyp4>=500) 
      {
         ballxptmp=ballxp2;
          ballxp2=ballxp4;
          ballxp4=ballxptmp;
          ballyptmp=ballyp2;
          ballyp2=ballyp4;
          ballyp4=ballyptmp;
      }
      
      
      
      if(Score>25 && Score<130)  alphaB=Score+100;
      if(Score>75 && Score<180)  alphaR=Score+50; 
      
      
      //*** Draw to Screen ***
      BeginDrawing();
      ClearBackground(WHITE);
      DrawTexture(background,0,0,Color{255,255,255,75});
      
      if((Score>=150 && Score<=160) || (Score>=260 && Score<=280) || (Score>=350 && Score<=380) || (Score>=450 && Score<500)) 
      {
      for(int i=1;i<26;i++){  
          if(i%2==0) DrawRectangle(0,i*29.6,800,30,Color{230,41,55,alphaBG});
          else DrawRectangle(0,i*29.6,800,30,Color{0,121,241,alphaBG}); }
         if(alphaBG<255) alphaBG++;
      }
      if(Score==150 || Score==280 || Score==380 || Score==500) alphaBG=0;
      
      if(Score>=500)
      {
          StopMusicStream(music2); _sleep(100); PlayMusicStream(music3);
          while(!WindowShouldClose())
          {
            UpdateMusicStream(music3);
            BeginDrawing();
            ClearBackground(BLACK);             
            DrawText("YOU WIN !!!",200,350,80,RED);
            DrawText("Congratulations",200,450,50,BLUE);  
            EndDrawing();            
          }
      }
      
      DrawRectangle(0,0,800,30,Color{0,121,241,150});
      DrawRectangle(0,770,800,30,Color{230,41,55,150});
      DrawCircle(ballxp1,ballyp1,ballradius1,BLUE);
      DrawCircle(ballxp2,ballyp2,ballradius2,RED);
      DrawCircle(ballxp3,ballyp3,ballradius3,Color{0,121,241,alphaB});
      DrawCircle(ballxp4,ballyp4,ballradius4,Color{230,41,55,alphaR});
      DrawRectangle(paddlexp,paddleyp,500,30,GREEN);
      DrawText(TextFormat("Score: %i", Score), 10, 10, 20, BLACK);
      DrawText(TextFormat("High Score: %i", HighScore), 640, 10, 20, BLACK);
      if(Score>=25  && alphaText1>=0) {DrawText("Phantom Vision",230,200,50,Color{0,121,241,alphaText1});alphaText1--;}
      if(Score>=75  && alphaText2>=0) {DrawText("Phantom Vision",230,600,50,Color{230,41,55,alphaText2});alphaText2--;}
      if(Score>=250 && alphaText3>=0) {DrawText("Phantom Echoes",230,200,50,Color{0,121,241,alphaText3});DrawText("Phantom Echoes",230,600,50,Color{230,41,55,alphaText3});alphaText3--;}
      EndDrawing();
      
      // *** Pause Screen ***
      if(IsKeyDown(KEY_P))
      while(!(IsKeyDown(KEY_R)))
          {
              BeginDrawing();
              ClearBackground(BEIGE);
              DrawText("GAME PAUSED",170,350,60,MAROON);
              DrawText("Press R to return to Game",120,450,40,BLACK);
              EndDrawing();
          }
               
      
  }
  
  UnloadTexture(background);
  UnloadSound(pong);  
  UnloadSound(gameOver);  
  CloseWindow();
  CloseAudioDevice();
  StopMusicStream(music2);
  UnloadMusicStream(music1);
  UnloadMusicStream(music2);
  UnloadMusicStream(music3);
  
}
