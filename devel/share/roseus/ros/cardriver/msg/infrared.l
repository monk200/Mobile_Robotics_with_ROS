;; Auto-generated. Do not edit!


(when (boundp 'cardriver::infrared)
  (if (not (find-package "CARDRIVER"))
    (make-package "CARDRIVER"))
  (shadow 'infrared (find-package "CARDRIVER")))
(unless (find-package "CARDRIVER::INFRARED")
  (make-package "CARDRIVER::INFRARED"))

(in-package "ROS")
;;//! \htmlinclude infrared.msg.html


(defclass cardriver::infrared
  :super ros::object
  :slots (_left _middle _right _rearLeft _rearRight ))

(defmethod cardriver::infrared
  (:init
   (&key
    ((:left __left) 0)
    ((:middle __middle) 0)
    ((:right __right) 0)
    ((:rearLeft __rearLeft) 0)
    ((:rearRight __rearRight) 0)
    )
   (send-super :init)
   (setq _left (round __left))
   (setq _middle (round __middle))
   (setq _right (round __right))
   (setq _rearLeft (round __rearLeft))
   (setq _rearRight (round __rearRight))
   self)
  (:left
   (&optional __left)
   (if __left (setq _left __left)) _left)
  (:middle
   (&optional __middle)
   (if __middle (setq _middle __middle)) _middle)
  (:right
   (&optional __right)
   (if __right (setq _right __right)) _right)
  (:rearLeft
   (&optional __rearLeft)
   (if __rearLeft (setq _rearLeft __rearLeft)) _rearLeft)
  (:rearRight
   (&optional __rearRight)
   (if __rearRight (setq _rearRight __rearRight)) _rearRight)
  (:serialization-length
   ()
   (+
    ;; uint8 _left
    1
    ;; uint8 _middle
    1
    ;; uint8 _right
    1
    ;; uint8 _rearLeft
    1
    ;; uint8 _rearRight
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _left
       (write-byte _left s)
     ;; uint8 _middle
       (write-byte _middle s)
     ;; uint8 _right
       (write-byte _right s)
     ;; uint8 _rearLeft
       (write-byte _rearLeft s)
     ;; uint8 _rearRight
       (write-byte _rearRight s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _left
     (setq _left (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _middle
     (setq _middle (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _right
     (setq _right (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _rearLeft
     (setq _rearLeft (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _rearRight
     (setq _rearRight (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get cardriver::infrared :md5sum-) "8763b3893fce39888eb6c9b2ac70a0e5")
(setf (get cardriver::infrared :datatype-) "cardriver/infrared")
(setf (get cardriver::infrared :definition-)
      "uint8 left
uint8 middle
uint8 right
uint8 rearLeft
uint8 rearRight


")



(provide :cardriver/infrared "8763b3893fce39888eb6c9b2ac70a0e5")


