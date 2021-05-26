; Auto-generated. Do not edit!


(cl:in-package cardriver-msg)


;//! \htmlinclude infrared.msg.html

(cl:defclass <infrared> (roslisp-msg-protocol:ros-message)
  ((left
    :reader left
    :initarg :left
    :type cl:fixnum
    :initform 0)
   (middle
    :reader middle
    :initarg :middle
    :type cl:fixnum
    :initform 0)
   (right
    :reader right
    :initarg :right
    :type cl:fixnum
    :initform 0)
   (rearLeft
    :reader rearLeft
    :initarg :rearLeft
    :type cl:fixnum
    :initform 0)
   (rearRight
    :reader rearRight
    :initarg :rearRight
    :type cl:fixnum
    :initform 0))
)

(cl:defclass infrared (<infrared>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <infrared>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'infrared)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name cardriver-msg:<infrared> is deprecated: use cardriver-msg:infrared instead.")))

(cl:ensure-generic-function 'left-val :lambda-list '(m))
(cl:defmethod left-val ((m <infrared>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader cardriver-msg:left-val is deprecated.  Use cardriver-msg:left instead.")
  (left m))

(cl:ensure-generic-function 'middle-val :lambda-list '(m))
(cl:defmethod middle-val ((m <infrared>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader cardriver-msg:middle-val is deprecated.  Use cardriver-msg:middle instead.")
  (middle m))

(cl:ensure-generic-function 'right-val :lambda-list '(m))
(cl:defmethod right-val ((m <infrared>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader cardriver-msg:right-val is deprecated.  Use cardriver-msg:right instead.")
  (right m))

(cl:ensure-generic-function 'rearLeft-val :lambda-list '(m))
(cl:defmethod rearLeft-val ((m <infrared>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader cardriver-msg:rearLeft-val is deprecated.  Use cardriver-msg:rearLeft instead.")
  (rearLeft m))

(cl:ensure-generic-function 'rearRight-val :lambda-list '(m))
(cl:defmethod rearRight-val ((m <infrared>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader cardriver-msg:rearRight-val is deprecated.  Use cardriver-msg:rearRight instead.")
  (rearRight m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <infrared>) ostream)
  "Serializes a message object of type '<infrared>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'left)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'middle)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'right)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'rearLeft)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'rearRight)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <infrared>) istream)
  "Deserializes a message object of type '<infrared>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'left)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'middle)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'right)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'rearLeft)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'rearRight)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<infrared>)))
  "Returns string type for a message object of type '<infrared>"
  "cardriver/infrared")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'infrared)))
  "Returns string type for a message object of type 'infrared"
  "cardriver/infrared")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<infrared>)))
  "Returns md5sum for a message object of type '<infrared>"
  "8763b3893fce39888eb6c9b2ac70a0e5")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'infrared)))
  "Returns md5sum for a message object of type 'infrared"
  "8763b3893fce39888eb6c9b2ac70a0e5")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<infrared>)))
  "Returns full string definition for message of type '<infrared>"
  (cl:format cl:nil "uint8 left~%uint8 middle~%uint8 right~%uint8 rearLeft~%uint8 rearRight~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'infrared)))
  "Returns full string definition for message of type 'infrared"
  (cl:format cl:nil "uint8 left~%uint8 middle~%uint8 right~%uint8 rearLeft~%uint8 rearRight~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <infrared>))
  (cl:+ 0
     1
     1
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <infrared>))
  "Converts a ROS message object to a list"
  (cl:list 'infrared
    (cl:cons ':left (left msg))
    (cl:cons ':middle (middle msg))
    (cl:cons ':right (right msg))
    (cl:cons ':rearLeft (rearLeft msg))
    (cl:cons ':rearRight (rearRight msg))
))
