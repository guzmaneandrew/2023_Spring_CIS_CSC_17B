<?php

/* 
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Scripting/EmptyPHP.php to edit this template
 */

class Survey {
    private $questions;
    private $status;

    public function __construct(array $questions) {
        $this->questions = $questions;
        $this->status = true;
    }

    public function addQuestion(Question $question) {
        $this->questions[] = $question;
    }
    
    public function updtStatus() {
        $this->status=!$this->status;
    }

    public function getQuestions() {
        return $this->questions;
    }
    
    public function getStatus() {
        return $this->status;
    }
}
