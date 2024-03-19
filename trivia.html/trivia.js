// Correct selection of the container using class
let body = document.querySelector('.container'); // Use .container for class selection

document.querySelector('#correct').addEventListener('click', function(){
    this.style.backgroundColor = 'green';
    document.getElementById("ShowAnswer").innerHTML = "Correct!";
    setTimeout(() => {
        this.style.backgroundColor = ''; // Reset to original after 2 seconds
        document.getElementById("ShowAnswer").innerHTML = " ";
    }, 2000);
});

// Handling incorrect buttons
let incorrectButtons = document.querySelectorAll('.incorrect');
incorrectButtons.forEach(button => {
    button.addEventListener('click', function(){
        this.style.backgroundColor = 'red';
        document.getElementById("ShowAnswer").innerHTML = "Incorrect!";
        setTimeout(() => {
            this.style.backgroundColor = ''; // Reset to original after 2 seconds
            document.getElementById("ShowAnswer").innerHTML = " ";
        }, 2000);
    });
});


// Assuming you'll change the type="submit" to a button with id="check" for the free response part
document.querySelector('#submit').addEventListener("click", function(){ // Use #submit for the corrected id
    let input = document.querySelector("input[type='text']"); // More specific selector for the text input
    if (input.value.toLowerCase() === "the milky way"){ // Use === for strict equality check
        input.style.backgroundColor = "green";
        document.querySelector("#ShowAnswer").innerHTML = "Correct!";
        setTimeout(() => {
            this.style.backgroundColor = ''; // Reset to original after 2 seconds
            document.getElementById("ShowAnswer").innerHTML = " ";
        }, 2000);
    } else {
        input.style.backgroundColor = "red";
        document.querySelector("#ShowAnswer").innerHTML = "Incorrect!";
        setTimeout(() => {
            this.style.backgroundColor = ''; // Reset to original after 2 seconds
            document.getElementById("ShowAnswer").innerHTML = " ";
        }, 2000);
    }
});
