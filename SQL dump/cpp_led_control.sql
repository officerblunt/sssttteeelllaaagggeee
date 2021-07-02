-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Хост: 127.0.0.1
-- Время создания: Июл 02 2021 г., 09:43
-- Версия сервера: 10.4.19-MariaDB
-- Версия PHP: 8.0.7

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- База данных: `cpp_led_control`
--

-- --------------------------------------------------------

--
-- Структура таблицы `word_to_led`
--

CREATE TABLE `word_to_led` (
  `word` varchar(20) NOT NULL,
  `led` varchar(5) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Дамп данных таблицы `word_to_led`
--

INSERT INTO `word_to_led` (`word`, `led`) VALUES
('1', 'A'),
('2', 'B'),
('3', 'C'),
('4', 'D'),
('5', 'E'),
('6', 'F'),
('7', 'G'),
('8', 'H'),
('9', 'I'),
('10', 'J'),
('11', 'K'),
('12', 'L'),
('13', 'M'),
('14', 'N'),
('15', 'O'),
('16', 'P'),
('LEFT', 'Y'),
('RIGHT', 'Z'),
('STOP', 'X');
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
