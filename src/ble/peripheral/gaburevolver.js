var bleno = require('bleno');
var ffi = require('ffi');
var util = require('util');
var ToyHackService = require('./toyhack-service');


/* Characteristics */

function OpenSetter(hGaburevolver){
  OpenSetter.super_.call(this, {
    uuid: '0bd173ff1029456d9df38c58a2962001',
    properties: ['writeWithoutResponse'],
    descriptors: [
      new bleno.Descriptor({
        uuid: '2901',
        value: 'ガブリボルバーオープン'
      })
    ]
  });

  this.gaburevolver = hGaburevolver;
};

function SetJudenchi(hGaburevolver){
  SetJudenchi.super_.call(this, {
    uuid: '0bd173ff1029456d9df38c58a2962002',
    properties: ['writeWithoutResponse'],
    descriptors: [
      new bleno.Descriptor({
        uuid: '2901',
        value: '獣電池セット'
      })
    ]
  });

  this.gaburevolver = hGaburevolver;
};

function CloseSetter(hGaburevolver){
  CloseSetter.super_.call(this, {
    uuid: '0bd173ff1029456d9df38c58a2962003',
    properties: ['writeWithoutResponse'],
    descriptors: [
      new bleno.Descriptor({
        uuid: '2901',
        value: 'ガブリボルバークローズ'
      })
    ]
  });

  this.gaburevolver = hGaburevolver;
};

function Rotate(hGaburevolver){
  Rotate.super_.call(this, {
    uuid: '0bd173ff1029456d9df38c58a2962004',
    properties: ['writeWithoutResponse'],
    descriptors: [
      new bleno.Descriptor({
        uuid: '2901',
        value: '回転'
      })
    ]
  });

  this.gaburevolver = hGaburevolver;
};

function Trigger(hGaburevolver){
  Trigger.super_.call(this, {
    uuid: '0bd173ff1029456d9df38c58a2962005',
    properties: ['writeWithoutResponse'],
    descriptors: [
      new bleno.Descriptor({
        uuid: '2901',
        value: 'トリガー'
      })
    ]
  });

  this.gaburevolver = hGaburevolver;
};

function DockMinityra(hGaburevolver){
  DockMinityra.super_.call(this, {
    uuid: '0bd173ff1029456d9df38c58a2962006',
    properties: ['writeWithoutResponse'],
    descriptors: [
      new bleno.Descriptor({
        uuid: '2901',
        value: 'ミニティラドッキング'
      })
    ]
  });

  this.gaburevolver = hGaburevolver;
};

function UndockMinityra(hGaburevolver){
  UndockMinityra.super_.call(this, {
    uuid: '0bd173ff1029456d9df38c58a2962007',
    properties: ['writeWithoutResponse'],
    descriptors: [
      new bleno.Descriptor({
        uuid: '2901',
        value: 'ミニティラドッキング解除'
      })
    ]
  });

  this.gaburevolver = hGaburevolver;
};

function DockGaburicalibur(hGaburevolver){
  DockGaburicalibur.super_.call(this, {
    uuid: '0bd173ff1029456d9df38c58a2962008',
    properties: ['writeWithoutResponse'],
    descriptors: [
      new bleno.Descriptor({
        uuid: '2901',
        value: 'ガブリカリバードッキング'
      })
    ]
  });

  this.gaburevolver = hGaburevolver;
};

function UndockGaburicalibur(hGaburevolver){
  UndockGaburicalibur.super_.call(this, {
    uuid: '0bd173ff1029456d9df38c58a2962009',
    properties: ['writeWithoutResponse'],
    descriptors: [
      new bleno.Descriptor({
        uuid: '2901',
        value: 'ガブリカリバードッキング解除'
      })
    ]
  });

  this.gaburevolver = hGaburevolver;
};

util.inherits(OpenSetter, bleno.Characteristic);
util.inherits(SetJudenchi, bleno.Characteristic);
util.inherits(CloseSetter, bleno.Characteristic);
util.inherits(Rotate, bleno.Characteristic);
util.inherits(Trigger, bleno.Characteristic);
util.inherits(DockMinityra, bleno.Characteristic);
util.inherits(UndockMinityra, bleno.Characteristic);
util.inherits(DockGaburicalibur, bleno.Characteristic);
util.inherits(UndockGaburicalibur, bleno.Characteristic);

OpenSetter.prototype.onWriteRequest =
                              function(data, offset, withoutResponse, callback){
  if(offset){
    callback(this.RESULT_ATTR_NOT_LONG);
  }
  else if(data.length != 1){
    callback(this.RESULT_INVALID_ATTRIBUTE_LENGTH);
  }
  else{
    var id = data.readUInt8(0); // dummy
    this.gaburevolver.OpenSetter();
  }

};

SetJudenchi.prototype.onWriteRequest =
                              function(data, offset, withoutResponse, callback){
  if(offset){
    callback(this.RESULT_ATTR_NOT_LONG);
  }
  else if(data.length != 2){
    callback(this.RESULT_INVALID_ATTRIBUTE_LENGTH);
  }
  else{
    var lower_sw = data.readUInt8(0);
    var upper_sw = data.readUInt8(1);
    this.gaburevolver.SetJudenchi(lower_sw, upper_sw);
  }

};

CloseSetter.prototype.onWriteRequest =
                              function(data, offset, withoutResponse, callback){
  if(offset){
    callback(this.RESULT_ATTR_NOT_LONG);
  }
  else if(data.length != 1){
    callback(this.RESULT_INVALID_ATTRIBUTE_LENGTH);
  }
  else{
    var id = data.readUInt8(0); // dummy
    this.gaburevolver.CloseSetter();
  }

};

Rotate.prototype.onWriteRequest =
                              function(data, offset, withoutResponse, callback){
  if(offset){
    callback(this.RESULT_ATTR_NOT_LONG);
  }
  else if(data.length != 1){
    callback(this.RESULT_INVALID_ATTRIBUTE_LENGTH);
  }
  else{
    var dummy = data.readUInt8(0); // dummy
    this.gaburevolver.Rotate();
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
    var dummy = data.readUInt8(0); // dummy
    this.gaburevolver.Rotate();
  }

};

DockMinityra.prototype.onWriteRequest =
                              function(data, offset, withoutResponse, callback){
  if(offset){
    callback(this.RESULT_ATTR_NOT_LONG);
  }
  else if(data.length != 1){
    callback(this.RESULT_INVALID_ATTRIBUTE_LENGTH);
  }
  else{
    var dummy = data.readUInt8(0); // dummy
    this.gaburevolver.DockMinityra();
  }

};

UndockMinityra.prototype.onWriteRequest =
                              function(data, offset, withoutResponse, callback){
  if(offset){
    callback(this.RESULT_ATTR_NOT_LONG);
  }
  else if(data.length != 1){
    callback(this.RESULT_INVALID_ATTRIBUTE_LENGTH);
  }
  else{
    var dummy = data.readUInt8(0); // dummy
    this.gaburevolver.UndockMinityra();
  }

};

DockGaburicalibur.prototype.onWriteRequest =
                              function(data, offset, withoutResponse, callback){
  if(offset){
    callback(this.RESULT_ATTR_NOT_LONG);
  }
  else if(data.length != 1){
    callback(this.RESULT_INVALID_ATTRIBUTE_LENGTH);
  }
  else{
    var dummy = data.readUInt8(0); // dummy
    this.gaburevolver.DockGaburicalibur();
  }

};

UndockGaburicalibur.prototype.onWriteRequest =
                              function(data, offset, withoutResponse, callback){
  if(offset){
    callback(this.RESULT_ATTR_NOT_LONG);
  }
  else if(data.length != 1){
    callback(this.RESULT_INVALID_ATTRIBUTE_LENGTH);
  }
  else{
    var dummy = data.readUInt8(0); // dummy
    this.gaburevolver.UndockGaburicalibur();
  }

};


/* Service */

function GaburevolverService(libname){
  this.libgaburevolver = ffi.Library(libname, {
    'SetupGPIO': ['int', []],
    'OpenSetter': ['int', []],
    'SetJudenchi': ['int', ['int', 'int']],
    'CloseSetter': ['int', []],
    'Rotate': ['int', []],
    'Trigger': ['int', []],
    'DockMinityra': ['int', []],
    'UndockMinityra': ['int', []],
    'DockGaburicalibur': ['int', []],
    'UndockGaburicalibur': ['int', []]
  });

  GaburevolverService.super_.call(this, {
    uuid: '0bd173ff1029456d9df38c58a2962000',
    characteristics: [
      new OpenSetter(this.libgaburevolver),
      new SetJudenchi(this.libgaburevolver),
      new CloseSetter(this.libgaburevolver),
      new Rotate(this.libgaburevolver),
      new Trigger(this.libgaburevolver),
      new DockMinityra(this.libgaburevolver),
      new UndockMinityra(this.libgaburevolver),
      new DockGaburicalibur(this.libgaburevolver),
      new UndockGaburicalibur(this.libgaburevolver)
    ]
  });

  this.libgaburevolver.SetupGPIO();
}

util.inherits(GaburevolverService, ToyHackService);

GaburevolverService.prototype.getModuleName = function(){
  return 'Gaburevolver';
};

module.exports = GaburevolverService;
