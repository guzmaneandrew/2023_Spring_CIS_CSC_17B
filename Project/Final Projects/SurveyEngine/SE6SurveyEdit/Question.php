<?php

/*
 * Click nbfs:://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs:://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

class Question {

    private $question;
    private $typeInt;
    private $numRespOptions;
    private $respOptions;

    const SINGLE = 1;
    const MULTIPLE = 2;
    const WRITEIN = 3;

    public function __construct() {
        $this->question = "This is the question.";
        $this->typeInt = 1;
        $this->numRespOptions = 4;
        $this->respOptions = ["Option 1","Option 2","Option 3","Option 4"];
    }

//    public function __construct($q, $type, $numResp, array $options) {
//        $this->question = $q;
//        $this->typeInt = $type;
//        $this->numRespOptions = $numResp;
//        $this->respOptions = $options;
//    }

    public function setQ($q) {
        $this->question = $q;
    }

    public function setType($t) {
        $this->typeInt = 1;
    }

    public function setNumResp($n) {
        $this->numRespOptions = $n;
    }

    public function setRespOptions($options) {
        $this->respOptions = $options;
    }

    public function setResp($i) {
        if ($i >= 0 && $i < count($this->respOptions)) {
            $this->respOptions[$i] = readline("Enter New Response Option: ");
        }
    }

    public function addResp() {
        $this->numRespOptions++;
        $response = readline("Enter New Response Option: ");
        array_push($this->respOptions, $response);
    }

    public function deleteROpt($i) {
        $this->numRespOptions--;
        array_splice($this->respOptions, $i, 1);
    }

    public function getQ() {
        return $this->question;
    }

    public function getType() {
        return $this->typeInt;
    }

    public function getNumResp() {
        return count($this->respOptions);
    }

    public function getRespOptions() {
        return $this->respOptions;
    }

    public function dispType() {
        if ($this->typeInt == self::SINGLE) {
            echo "Single Choice";
        } elseif ($this->typeInt == self::MULTIPLE) {
            echo "Multiple Choice";
        } elseif ($this->typeInt == self::WRITEIN) {
            echo "Multiple Choice/Write-In Response";
        } else {
            echo " ";
        }
        echo "<br>";
    }

    public function toString() {
        echo "Question: " . $this->question . "<br>";
        echo "Type: ";
        $this->dispType() . "<br>";
        echo "Response Options: " . $this->numRespOptions . "<br>";
        for ($i = 0; $i < $this->numRespOptions; $i++) {
            echo str_pad($i + 1, 3) . ") " . $this->respOptions[$i] . "<br>";
        }
        echo "<br>";
    }

}

?>