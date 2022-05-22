
/* Declare and implement your function here 
eg: function example(parameter_name1,parameter_name2....){}
Handle the input/output from main()
*/

process.stdin.resume();
process.stdin.setEncoding('ascii');

var input_stdin = "";
var input_stdin_array = "";
var input_currentline = 0;

process.stdin.on('data', function (data) {
input_stdin += data;
});

process.stdin.on('end', function () {
input_stdin_array = input_stdin.split("\n");
main();    
});

function readLine() {
return input_stdin_array[input_currentline++];
}

function power(x, n) {
	if (n==0) return 1;
    return x * power(x, n-1);
}

function main() {

    /* Read your input here 
    eg: For string variables:   let str = String(readLine()); 
        For int variables: let var_name = parseInt(readLine());
        For arrays : const arr = readLine().replace(/\s+$/g, '').split(' ');
    */

    /*
    Call your function with the input/parameters read above
    eg: let x = example(var_name, arr);
    */

   /*
   Log your output here 
   eg: console.log(x);
   */
    var x = parseInt(readLine());
	var n = parseInt(readLine());
	console.log(power(x, n));

}