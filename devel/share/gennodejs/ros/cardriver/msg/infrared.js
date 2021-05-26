// Auto-generated. Do not edit!

// (in-package cardriver.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class infrared {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.left = null;
      this.middle = null;
      this.right = null;
      this.rearLeft = null;
      this.rearRight = null;
    }
    else {
      if (initObj.hasOwnProperty('left')) {
        this.left = initObj.left
      }
      else {
        this.left = 0;
      }
      if (initObj.hasOwnProperty('middle')) {
        this.middle = initObj.middle
      }
      else {
        this.middle = 0;
      }
      if (initObj.hasOwnProperty('right')) {
        this.right = initObj.right
      }
      else {
        this.right = 0;
      }
      if (initObj.hasOwnProperty('rearLeft')) {
        this.rearLeft = initObj.rearLeft
      }
      else {
        this.rearLeft = 0;
      }
      if (initObj.hasOwnProperty('rearRight')) {
        this.rearRight = initObj.rearRight
      }
      else {
        this.rearRight = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type infrared
    // Serialize message field [left]
    bufferOffset = _serializer.uint8(obj.left, buffer, bufferOffset);
    // Serialize message field [middle]
    bufferOffset = _serializer.uint8(obj.middle, buffer, bufferOffset);
    // Serialize message field [right]
    bufferOffset = _serializer.uint8(obj.right, buffer, bufferOffset);
    // Serialize message field [rearLeft]
    bufferOffset = _serializer.uint8(obj.rearLeft, buffer, bufferOffset);
    // Serialize message field [rearRight]
    bufferOffset = _serializer.uint8(obj.rearRight, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type infrared
    let len;
    let data = new infrared(null);
    // Deserialize message field [left]
    data.left = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [middle]
    data.middle = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [right]
    data.right = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [rearLeft]
    data.rearLeft = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [rearRight]
    data.rearRight = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 5;
  }

  static datatype() {
    // Returns string type for a message object
    return 'cardriver/infrared';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '8763b3893fce39888eb6c9b2ac70a0e5';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint8 left
    uint8 middle
    uint8 right
    uint8 rearLeft
    uint8 rearRight
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new infrared(null);
    if (msg.left !== undefined) {
      resolved.left = msg.left;
    }
    else {
      resolved.left = 0
    }

    if (msg.middle !== undefined) {
      resolved.middle = msg.middle;
    }
    else {
      resolved.middle = 0
    }

    if (msg.right !== undefined) {
      resolved.right = msg.right;
    }
    else {
      resolved.right = 0
    }

    if (msg.rearLeft !== undefined) {
      resolved.rearLeft = msg.rearLeft;
    }
    else {
      resolved.rearLeft = 0
    }

    if (msg.rearRight !== undefined) {
      resolved.rearRight = msg.rearRight;
    }
    else {
      resolved.rearRight = 0
    }

    return resolved;
    }
};

module.exports = infrared;
