document.addEventListener("DOMContentLoaded", initialize);

/**
 * Función de inicialización que configura los event listeners para la validación del formulario.
 */
function initialize() {
    // Selecciona los elementos del formulario
    const password = document.querySelector("#password");
    const repeatPassword = document.querySelector("#confirmation");
    const form = document.querySelector("form");

    form.addEventListener("submit", submitRegister);

    repeatPassword.addEventListener("keydown", function(event) {
        // Limpia el mensaje de validez personalizado previo
        repeatPassword.setCustomValidity("");
    });

    /**
     * Función que maneja la validación y el envío del formulario.
     * @param {Event} event - El evento de envío del formulario.
     */
    function submitRegister(event) {
        // Limpia el mensaje de validez personalizado previo
        repeatPassword.setCustomValidity("");

        // Comprueba si las contraseñas coinciden
        if (repeatPassword.value !== password.value) {
            // Evita que el formulario se envíe si las contraseñas no coinciden
            event.preventDefault();
            // Establece un mensaje de validez personalizado
            repeatPassword.setCustomValidity("Passwords do not match!");
            // Muestra el mensaje de error
            repeatPassword.reportValidity();
        } else {
            // Limpia el mensaje de error si las contraseñas coinciden
            repeatPassword.setCustomValidity("");
        }
    }
}
