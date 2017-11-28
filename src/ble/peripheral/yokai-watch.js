var bleno = require('bleno');
var ffi = require('ffi');
var util = require('util');
var ToyHackService = require('./toyhack-service');


/* Characteristics */

function SetMedal(hWatch){
  SetMedal.super_.call(this, {
    uuid: 'f1205471f8cd466ca9a8a4e377044001',
    properties: ['writeWithoutResponse'],
    descriptors: [
      new bleno.Descriptor({
        uuid: '2901',
        value: '妖怪メダルセット'
      })
    ]
  });

  this.watch = hWatch;
};

function EjectMedal(hWatch){
  EjectMedal.super_.call(this, {
    uuid: 'f1205471f8cd466ca9a8a4e377044002',
    properties: ['writeWithoutResponse'],
    descriptors: [
      new bleno.Descriptor({
        uuid: '2901',
        value: '妖怪メダルイジェクト'
      })
    ]
  });

  this.watch = hWatch;
};

util.inherits(SetMedal, bleno.Characteristic);
util.inherits(EjectMedal, bleno.Characteristic);

SetMedal.prototype.onWriteRequest =
                              function(data, offset, withoutResponse, callback){
  if(offset){
    callback(this.RESULT_ATTR_NOT_LONG);
  }
  else if(data.length != 1){
    callback(this.RESULT_INVALID_ATTRIBUTE_LENGTH);
  }
  else{
    var pattern = data.readUInt8(0);
    this.watch.SetMedal(pattern);
  }

};

EjectMedal.prototype.onWriteRequest =
                              function(data, offset, withoutResponse, callback){
  if(offset){
    callback(this.RESULT_ATTR_NOT_LONG);
  }
  else if(data.length != 1){
    callback(this.RESULT_INVALID_ATTRIBUTE_LENGTH);
  }
  else{
    var dummy = data.readUInt8(0); // dummy
    this.watch.EjectMedal();
  }

};


/* Service */

function YokaiWatchService(libname){
  this.libyokaiwatch = ffi.Library(libname, {
    'SetupGPIO': ['int', []],
    'SetMedal': ['int', ['int']],
    'EjectMedal': ['int', []]
  });

  YokaiWatchService.super_.call(this, {
    uuid: 'f1205471f8cd466ca9a8a4e377044000',
    characteristics: [
      new SetMedal(this.libyokaiwatch),
      new EjectMedal(this.libyokaiwatch)
    ]
  });

  this.libyokaiwatch.SetupGPIO();
}

util.inherits(YokaiWatchService, ToyHackService);

YokaiWatchService.prototype.getModuleName = function(){
  return 'Yokai Watch';
};

module.exports = MinityraService;
