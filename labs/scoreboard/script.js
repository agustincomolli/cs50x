let team1 = 0;
let team2 = 0;
const TOTAL_POINTS = 5;

document.querySelector('#add1').onclick = function() {
    team1 = team1 + 1;
    document.querySelector('#score1').innerHTML = team1;
    if (team1 == TOTAL_POINTS) {
        document.querySelector("#result").innerText = "¡El Equipo 1 ha ganado! 🥳";
        // alert("¡El Equipo 1 ha ganado! 🥳");
        document.querySelector('#add1').disabled = true;
        document.querySelector('#add2').disabled = true;
    }
}

document.querySelector('#add2').onclick = function() {
    team2 = team2 + 1;
    document.querySelector('#score2').innerHTML = team2;
    if (team2 == TOTAL_POINTS) {
        document.querySelector("#result").innerText = "¡El Equipo 2 ha ganado! 🥳";
        // alert("¡El Equipo 2 ha ganado! 🥳");
        document.querySelector('#add1').disabled = true;
        document.querySelector('#add2').disabled = true;
    }
}
