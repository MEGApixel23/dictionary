const fs = require('fs');
const readline = require('readline');

const lineReader = readline.createInterface({
  input: fs.createReadStream('dict.xml')
});

const parseData = (str) => {
  const english = str.match(/<k>([a-zA-Z]+)<\/k>/i)[1].toLowerCase();
  const ukrainian = str.match(/\&quot;(.+)\&quot;/i)[1].toLowerCase();

  return `${english}:${ukrainian}`;
};

const appendToDictionary = (str) => {
  fs.appendFileSync(__dirname + '/dictionary.txt', str + "\r");
};

let block = '';

lineReader.on('line', (line) => {
  if (line.match(/\&quot;/gi)) {
	block += line;
	
	appendToDictionary(parseData(block));
	block = '';
  } else if (line.match(/\<ar>/gi)) {
	block += line;
  }
});