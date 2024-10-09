let input = document.querySelector("input");

document.addEventListener("DOMContentLoaded", initialize);

function initialize() {
    input.addEventListener("input", search);
};


async function search() {
    let response = await fetch(`/search?q=${input.value}`);
    let shows = await response.text();
    document.querySelector("ul").innerHTML = shows;
};
