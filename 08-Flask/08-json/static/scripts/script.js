/**
 * Aplicación de búsqueda de shows en tiempo real
 *
 * Este script implementa una funcionalidad de búsqueda en tiempo real
 * para una lista de shows (series de TV o películas). Realiza llamadas
 * a una API de búsqueda y actualiza dinámicamente los resultados en la página.
 */

// Selecciona el campo de entrada de búsqueda
let input = document.querySelector("input");

// Espera a que el DOM esté completamente cargado antes de inicializar
document.addEventListener("DOMContentLoaded", initialize);

/**
 * Inicializa la aplicación.
 * Configura el evento de entrada para activar la búsqueda.
 */
function initialize() {
    input.addEventListener("input", search);
}

/**
 * Realiza la búsqueda de shows basada en la entrada del usuario.
 * Hace una llamada a la API, procesa los resultados y actualiza el DOM.
 */
async function search() {
    // Realiza una llamada a la API con el término de búsqueda codificado
    let response = await fetch(`/search?q=${encodeURIComponent(input.value)}`);
    // Convierte la respuesta a JSON
    let shows = await response.json();
    // Genera el HTML para los resultados
    let html = "";
    for (let id in shows) {
        html += `<li>${shows[id].title} - ${shows[id].year}</li>`
    }
    // Actualiza la lista de resultados en el DOM
    document.querySelector("ul").innerHTML = html;
};
