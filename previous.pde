// 2 circles
void draw()
{
    rect(0,0,10000,10000);
    int pos = 500;
    int radius = sin(frameCount)*600;
    int diff = cos(frameCount)*600;
    fill(#00ff00);
    ellipse(pos, pos, radius, radius);
    fill(#000fff);
    ellipse(pos, pos, diff, diff);
}

// solar system
void draw()
{
    rect(0,0,10000,10000);
    int pos = 1000;

    // speed of movement
    int speedMecury = 10;
    int speedVenus = 8;
    int speedEarth = 10;
    int speedMoon = 5;

    // radius of movement
    int rMercury = 200;
    int rVenus = 300;
    int rEarth = 700;
    int sMoon = 200;

    // size
    int sizeMercury = 50;
    int sizeVenus = 100;
    int sizeEarth = 250;
    int sizeMoon = 50;
    
    // sun
    fill(#ffff00);
    ellipse(pos, pos, 200, 200);
    // mercury
    fill(#ff0000);
    ellipse(sin(frameCount/speedMecury)*rMercury+pos, cos(frameCount/speedMecury)*rMercury+pos, sizeMercury, sizeMercury);
    // venus
    fill(#ff5500);
    ellipse(sin(frameCount/speedVenus)*rVenus+pos, cos(frameCount/speedVenus)*rVenus+pos, sizeVenus, sizeVenus);
    // earth
    int fX = sin(frameCount/speedEarth)*rEarth+pos;
    int fY = cos(frameCount/speedEarth)*rEarth+pos;
    fill(#0000ff);
    ellipse(fX, fY, sizeEarth, sizeEarth);
    fill(#00ff00);
    ellipse(fX, fY, sizeEarth/2, sizeEarth/2);
    // the moon
    fill(#ffffff);
    ellipse(sin(frameCount/speedMoon)*sMoon+fX, cos(frameCount/speedMoon)*sMoon+fY, sizeMoon, sizeMoon);
}