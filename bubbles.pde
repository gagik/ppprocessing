// https://openprocessing.org/sketch/425051
int time = 0;

void setup(){
  size(600, 600);
  noFill();
  stroke(255);
}

void draw(){
  background(242);
  for(int i = 0; i < 360; i+=3){
    float x = cos(radians(i)) * 50 + width / 2;
    float y = sin(radians(i)) *100 + height / 2;
    float w = sin(radians(time+i )) * 200;
    w = abs(w);

    float col=map(i,0,360,120,255);
    fill(col,col,col);

    noStroke();
    fill(col,0,88);
    ellipse(x, y, w, w);
  }
  time++;
}