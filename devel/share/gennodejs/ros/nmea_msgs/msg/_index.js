
"use strict";

let Gpgsv = require('./Gpgsv.js');
let GpgsvSatellite = require('./GpgsvSatellite.js');
let Gpgga = require('./Gpgga.js');
let Gpgsa = require('./Gpgsa.js');
let Gprmc = require('./Gprmc.js');
let Sentence = require('./Sentence.js');

module.exports = {
  Gpgsv: Gpgsv,
  GpgsvSatellite: GpgsvSatellite,
  Gpgga: Gpgga,
  Gpgsa: Gpgsa,
  Gprmc: Gprmc,
  Sentence: Sentence,
};
