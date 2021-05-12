const fps=30;

function linearInterp(start,end,fraction) {
    return (end - start) * fraction + start;
}

function animateSky(){

    const RedStart = 135;
    const GreenStart = 206;
    const BlueStart = 235;
    const RedEnd = 30;
    const BlueEnd = 10;
    const GreenEnd = 10;

    const duration = 60;
    const ticks = duration * fps;

    let count = 0;
    let direction = 1;

    let sky = document.querySelector("#sky");

    return () => {
        count = (count + direction);

        if (count >= ticks) {
            direction = -1
            count = ticks;
        } else if (count <= 0) {
            direction = 1;
            count = 0;
        }

        let fraction = count / ticks;
        let red = linearInterp(RedStart, RedEnd, fraction);
        let green = linearInterp(GreenStart, GreenEnd, fraction);
        let blue = linearInterp(BlueStart, BlueEnd, fraction);

        sky.setAttribute("fill",`rgba(${red}, ${green},${blue}, 0.5`);
    }

}

setInterval(animateSky(), 1 / fps)

function parabola(x, offset, peak, falloff){

    return falloff * (x - offset) ** 2 + peak;

}

function parabolaSlope (x, offset, peak, falloff){

    return 2*falloff*(x-offset)

}

function animateArrow(){

    const offset = 300;
    const peak = -100;
    const falloff = 0.001;

    let arrow = document.querySelector("#arrow");

    const xMax = 600;
    const duration = 20;
    const ticks = duration * fps;
    count = 0;
    
    return ()=>{

        count = (count +1)%ticks;

        let x = linearInterp(0,xMax,count/ticks);
        let y = parabola(x,offset,peak,falloff);

        let angle = Math.atan(parabolaSlope(x, offset, peak, falloff)) * 180/Math.PI;
        arrow.setAttribute("transform", `translate(${x},${y}) rotate(${angle})`);


    }
}

setInterval(animateArrow(), 1/30);