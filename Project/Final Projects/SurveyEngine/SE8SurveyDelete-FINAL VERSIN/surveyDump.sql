-- MariaDB dump 10.19  Distrib 10.4.28-MariaDB, for osx10.10 (x86_64)
--
-- Host: 127.0.0.1    Database: survey_db
-- ------------------------------------------------------
-- Server version	10.4.28-MariaDB

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `entity_option`
--

DROP TABLE IF EXISTS `entity_option`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `entity_option` (
  `option_id` int(10) NOT NULL,
  `option` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`option_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `entity_option`
--

LOCK TABLES `entity_option` WRITE;
/*!40000 ALTER TABLE `entity_option` DISABLE KEYS */;
INSERT INTO `entity_option` VALUES (1,'A lot'),(2,'Some'),(3,'Not much'),(4,'It\'s my first time hearing about it now'),(5,'Ice cream'),(6,'Brownies'),(7,'Cookies'),(8,'Cake'),(9,'Red'),(10,'Orange'),(11,'Black'),(12,'Yellow'),(13,'Yes'),(14,'No');
/*!40000 ALTER TABLE `entity_option` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `entity_question`
--

DROP TABLE IF EXISTS `entity_question`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `entity_question` (
  `question_id` int(7) NOT NULL,
  `question` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`question_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `entity_question`
--

LOCK TABLES `entity_question` WRITE;
/*!40000 ALTER TABLE `entity_question` DISABLE KEYS */;
INSERT INTO `entity_question` VALUES (1,'How much, if at all, have you heard or read about cryptocurrencies such as Bitcoin or Ethereum?'),(2,'Do you own cryptocurrency?'),(3,'What is your favorite color?'),(4,'What are your 2 favorite desserts?');
/*!40000 ALTER TABLE `entity_question` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `entity_survey`
--

DROP TABLE IF EXISTS `entity_survey`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `entity_survey` (
  `survey_id` int(10) NOT NULL,
  `title` varchar(50) DEFAULT NULL,
  `is_active` tinyint(1) DEFAULT NULL,
  `numQuestions` int(7) DEFAULT NULL,
  `description` varchar(200) DEFAULT NULL,
  PRIMARY KEY (`survey_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `entity_survey`
--

LOCK TABLES `entity_survey` WRITE;
/*!40000 ALTER TABLE `entity_survey` DISABLE KEYS */;
INSERT INTO `entity_survey` VALUES (1,'Cryptocurrency',1,2,'What do you know about cryptocurrencies?'),(2,'Favorite Survey',0,2,'Describe your favorites'),(3,'Course Feedback',1,1,'Please provide feedback for your courses this semester');
/*!40000 ALTER TABLE `entity_survey` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `entity_user`
--

DROP TABLE IF EXISTS `entity_user`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `entity_user` (
  `user_id` int(7) NOT NULL AUTO_INCREMENT,
  `user_name` varchar(10) DEFAULT NULL,
  `password` varchar(10) DEFAULT NULL,
  `status` bit(1) DEFAULT NULL,
  PRIMARY KEY (`user_id`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `entity_user`
--

LOCK TABLES `entity_user` WRITE;
/*!40000 ALTER TABLE `entity_user` DISABLE KEYS */;
INSERT INTO `entity_user` VALUES (1,'test','test123',''),(2,'admin','admin123',''),(3,'user','user123','');
/*!40000 ALTER TABLE `entity_user` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `enum_question_type`
--

DROP TABLE IF EXISTS `enum_question_type`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `enum_question_type` (
  `question_type_id` int(10) NOT NULL,
  `question_type` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`question_type_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `enum_question_type`
--

LOCK TABLES `enum_question_type` WRITE;
/*!40000 ALTER TABLE `enum_question_type` DISABLE KEYS */;
INSERT INTO `enum_question_type` VALUES (1,'Single'),(2,'Multiple'),(3,'Write-In');
/*!40000 ALTER TABLE `enum_question_type` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `x_survey_question`
--

DROP TABLE IF EXISTS `x_survey_question`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `x_survey_question` (
  `x_survey_question_id` int(10) NOT NULL,
  `survey_id` int(10) DEFAULT NULL,
  `question_id` int(10) DEFAULT NULL,
  PRIMARY KEY (`x_survey_question_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `x_survey_question`
--

LOCK TABLES `x_survey_question` WRITE;
/*!40000 ALTER TABLE `x_survey_question` DISABLE KEYS */;
INSERT INTO `x_survey_question` VALUES (1,1,1),(2,1,2),(3,2,4),(4,2,5);
/*!40000 ALTER TABLE `x_survey_question` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `x_survey_question_answer`
--

DROP TABLE IF EXISTS `x_survey_question_answer`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `x_survey_question_answer` (
  `x_survey_question_answer` int(7) NOT NULL,
  `survey_id` int(10) DEFAULT NULL,
  `question_id` int(10) DEFAULT NULL,
  `answer_id` int(10) DEFAULT NULL,
  PRIMARY KEY (`x_survey_question_answer`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `x_survey_question_answer`
--

LOCK TABLES `x_survey_question_answer` WRITE;
/*!40000 ALTER TABLE `x_survey_question_answer` DISABLE KEYS */;
INSERT INTO `x_survey_question_answer` VALUES (1,1,1,1),(2,1,1,2),(3,1,1,3),(4,1,1,4),(5,1,1,5),(6,1,1,6);
/*!40000 ALTER TABLE `x_survey_question_answer` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-06-11 23:07:53
