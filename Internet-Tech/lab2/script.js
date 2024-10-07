let number = 18;
let str = 'Hi';
let bool = true;
let obl = {name: "Кирилл", age: 19};
let nothing = null;
let some;

const constNumber = 100;
const constStr = "Const string";
const constBool = false; 
const constObj = { city: "Новосиб" };
const constNull = null;
const constUndefined = undefined;

function other() {
    try {
        console.log("Переменная доступна:", local);
    } catch(error) {
        console.log("Переменная local не доступна")
    }
    try {
        console.log("Переменная доступна:", localConst);
    } catch(error) {
        console.log("Переменная localConst не доступна")
    }
    try {
        console.log("Переменная number доступна:", number);
    } catch(error) {
        console.log("Переменная number не доступна")
    }
}

function main() {
    let local = "local";
    const localConst = "const local";
    other();
}

main();

let numToString = String(123);
let strToNum = Number("456"); 
let boolToString = String(true); 
let strToBool = Boolean("Привет!");
let numToBool = Boolean(0); 

console.log("Число в строку:");
console.dir(numToString)
console.log("Строка в число:");
console.dir(strToNum)
console.log("Boolean в строку:");
console.dir(boolToString)
console.log("Строка в boolean:");
console.dir(strToBool)
console.log("Число в boolean (0):");
console.dir(numToBool)

// alert("Это сообщение через alert");
// let userName = prompt("Как вас зовут?");
// let isConfirmed = confirm("Вы уверены?");

// let i = 0;
// while(i < 3) {
//     alert("while = " + i);
//     i++;
// }

// for(let i = 0; i < 3; i++) {
//     alert("for = " + i);
// }

// let day = prompt("Введите день недели (число от 1 до 7):");
// switch (day) {
//     case "1":
//         alert("Понедельник");
//         break;
//     case "2":
//         alert("Вторник");
//         break;
//     case "3":
//         alert("Среда");
//         break;
//     case "4":
//         alert("Четверг");
//         break;
//     case "5":
//         alert("Пятница");
//         break;
//     case "6":
//         alert("Суббота");
//         break;
//     case "7":
//         alert("Воскресенье");
//         break;
//     default:
//         alert("Некорректный день недели");
// }


// let sayHi = function(name) {
//     alert("Привет " + name);
// }

// sayHi("Настя");
// sayHi("Егор");