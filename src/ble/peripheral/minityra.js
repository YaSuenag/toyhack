var bleno = require('bleno');
var ffi = require('ffi');
var util = require('util');
var ToyHackService = require('./toyhack-service');


/* Characteristics */

function SetJudenchi(hMinityra){
  SetJudenchi.super_.call(this, {
    uuid: 'b73244fb2df84cd583300f6b70d68001',
    properties: ['writeWithoutResponse'],
    descriptors: [
      new bleno.Descriptor({
        uuid: '2901',
        value: '獣電池セット'
      })
    ]
  });

  this.minityra = hMinityra;
};

function Gabu(hMinityra){
  Gabu.super_.call(this, {
    uuid: 'b73244fb2df84cd583300f6b70d68002',
    properties: ['writeWithoutResponse'],
    descriptors: [
      new bleno.Descriptor({
        uuid: '2901',
        value: 'ガブガブ'
      })
    ]
  });

  this.minityra = hMinityra;
};

function Kururincho(hMinityra){
  Kururincho.super_.call(this, {
    uuid: 'b73244fb2df84cd583300f6b70d68003',
    properties: ['writeWithoutResponse'],
    descriptors: [
      new bleno.Descriptor({
        uuid: '2901',
        value: 'クルリンチョ'
      })
    ]
  });

  this.minityra = hMinityra;
};

function Dock(hMinityra){
  Dock.super_.call(this, {
    uuid: 'b73244fb2df84cd583300f6b70d68004',
    properties: ['writeWithoutResponse'],
    descriptors: [
      new bleno.Descriptor({
        uuid: '2901',
        value: 'ドッキング'
      })
    ]
  });

  this.minityra = hMinityra;
};

function Trigger(hMinityra){
  Trigger.super_.call(this, {
    uuid: 'b73244fb2df84cd583300f6b70d68005',
    properties: ['writeWithoutResponse'],
    descriptors: [
      new bleno.Descriptor({
        uuid: '2901',
        value: 'トリガー'
      })
    ]
  });

  this.minityra = hMinityra;
};

function SideSwitch(hMinityra){
  SideSwitch.super_.call(this, {
    uuid: 'b73244fb2df84cd583300f6b70d68006',
    properties: ['writeWithoutResponse'],
    descriptors: [
      new bleno.Descriptor({
        uuid: '2901',
        value: '横スイッチ'
      })
    ]
  });

  this.minityra = hMinityra;
};

util.inherits(SetJudenchi, bleno.Characteristic);
util.inherits(Gabu, bleno.Characteristic);
util.inherits(Kururincho, bleno.Characteristic);
util.inherits(Dock, bleno.Characteristic);
util.inherits(Trigger, bleno.Characteristic);
util.inherits(SideSwitch, bleno.Characteristic);

SetJudenchi.prototype.onWriteRequest =
                              function(data, offset, withoutResponse, callback){
  if(offset){
    callback(this.RESULT_ATTR_NOT_LONG);
  }
  else if(data.length != 1){
    callback(this.RESULT_INVALID_ATTRIBUTE_LENGTH);
  }
  else{
    var id = data.readUInt8(0);
    this.minityra.SetJudenchi(id);
  }

};

Gabu.prototype.onWriteRequest =
                              function(data, offset, withoutResponse, callback){
  if(offset){
    callback(this.RESULT_ATTR_NOT_LONG);
  }
  else if(data.length != 1){
    callback(this.RESULT_INVALID_ATTRIBUTE_LENGTH);
  }
  else{
    var id = data.readUInt8(0); // dummy
    this.minityra.Gabu();
  }

};

Kururincho.prototype.onWriteRequest =
                              function(data, offset, withoutResponse, callback){
  if(offset){
    callback(this.RESULT_ATTR_NOT_LONG);
  }
  else if(data.length != 1){
    callback(this.RESULT_INVALID_ATTRIBUTE_LENGTH);
  }
  else{
    var mode = data.readUInt8(0);
    this.minityra.Kururincho(mode);
  }

};

Dock.prototype.onWriteRequest =
                              function(data, offset, withoutResponse, callback){
  if(offset){
    callback(this.RESULT_ATTR_NOT_LONG);
  }
  else if(data.length != 1){
    callback(this.RESULT_INVALID_ATTRIBUTE_LENGTH);
  }
  else{
    var mode = data.readUInt8(0);
    if(mode == 1){
      this.minityra.DockGaburevolver();
    }
    else{
      this.minityra.UndockGaburevolver();
    }
  }

};

Trigger.prototype.onWriteRequest =
                              function(data, offset, withoutResponse, callback){
  if(offset){
    callback(this.RESULT_ATTR_NOT_LONG);
  }
  else if(data.length != 1){
    callback(this.RESULT_INVALID_ATTRIBUTE_LENGTH);
  }
  else{
    var dummy = data.readUInt8(0);
    this.minityra.Trigger();
  }

};

SideSwitch.prototype.onWriteRequest =
                              function(data, offset, withoutResponse, callback){
  if(offset){
    callback(this.RESULT_ATTR_NOT_LONG);
  }
  else if(data.length != 1){
    callback(this.RESULT_INVALID_ATTRIBUTE_LENGTH);
  }
  else{
    var dummy = data.readUInt8(0);
    this.minityra.SideSwitch();
  }

};


/* Service */

function MinityraService(libname){
  this.libminityra = ffi.Library(libname, {
    'SetupGPIO': ['void', []],
    'SetJudenchi': ['int', ['int']],
    'Gabu': ['int', []],
    'Kururincho': ['int', ['int']],
    'DockGaburevolver': ['int', []],
    'UndockGaburevolver': ['int', []],
    'Trigger': ['int', []],
    'SideSwitch': ['int', []]
  });

  MinityraService.super_.call(this, {
    uuid: 'b73244fb2df84cd583300f6b70d68000',
    characteristics: [
      new SetJudenchi(this.libminityra),
      new Gabu(this.libminityra),
      new Kururincho(this.libminityra),
      new Dock(this.libminityra),
      new Trigger(this.libminityra),
      new SideSwitch(this.libminityra)
    ]
  });

  this.libminityra.SetupGPIO();
}

util.inherits(MinityraService, ToyHackService);

MinityraService.prototype.getModuleName = function(){
  return 'Minityra';
};

module.exports = MinityraService;
