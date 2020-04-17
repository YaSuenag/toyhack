var bleno = require('bleno');
var util = require('util');


function ToyHackService(options){
  ToyHackService.super_.call(this, options);
}

ToyHackService.prototype.getModuleName = function(){
  return undefined;
};


util.inherits(ToyHackService, bleno.PrimaryService);
module.exports = ToyHackService;

