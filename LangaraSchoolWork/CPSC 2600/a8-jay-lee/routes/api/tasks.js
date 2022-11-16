const express = require('express');
const router = express.Router();
const tasks = require('../../Tasks');
const uuid = require('uuid');
const members = require('../../../WorksheetExpress/members');

/**
 * @route GET api/tasks
 * @desc Retrives all tasks
 **/
router.get('/', (req, res) => res.json(tasks));

/**
 * @ TODO Task 1
 * @route GET api/tasks/:id
 * @desc Retrieves task with ID specified in URL
 **/
router.get('/:id', (req, res) => {
    const found = tasks.some(task => task.id == req.params.id);

    if (found) {
        res.json(tasks.filter(task => task.id == req.params.id));
    } else {
        res.status(400).json({ msg: `No task with the id of ${req.params.id}` });
    }
});

/**
 * @ TODO Task 3
 * @route POST api/tasks/
 * @desc Creates a new task
 **/
router.post('/', (req, res) => {

    const newTask = {
        id: uuid.v4(),
        taskName: req.body.taskName,
        completed: false,
        important: false
    }

    if (!newTask.taskName) {
        return res.status(400).json({ msg: "Please include task name" });
    }

    tasks.push(newTask);
    res.json(tasks);
});

/**
 * @ TODO Task 2
 * @route DELETE api/tasks/:id
 * @desc Deletes task with ID specified in URL
 **/
router.delete('/:id', (req, res) => {
    const found = tasks.some(task => task.id == req.params.id);

    if (found) {
        res.json({
            msg: "task deleted",
            tasks: tasks.filter(task => task.id != parseInt(req.params.id))
        })
    } else {
        res.status(400).json({ msg: `No task with the id of ${req.params.id}` });
    }
});

router.put('/:id', (req, res) => {
    const found = tasks.some(task => task.id == req.params.id);

    if (found && (req.body.taskName || req.body.completed || req.body.important)) {

        updatedTask = tasks.map((task) => {
            const nameTask = "";
            const completedTask = "";
            const bodyImportant = "";
            if (req.params.id == task.id) {
                if (req.body.completed) {
                    completedTask = req.body.completed;
                } else {
                    completedTask = task.completed;
                }
                if (req.body.taskName) {
                    nameTask = req.params.taskName;
                } else {
                    nameTask = task.taskName;
                }
                if (req.body.important) {
                    bodyImportant = req.params.important;
                } else {
                    bodyImportant = task.important;
                }
                return { ...task, completed: completedTask, taskName: nameTask, important: bodyImportant };
            }
        })
        res.json({
            msg: "task updated",
            tasks: tasks.filter(task => task.id == req.params.id)
        })
    } else {
        res.status(400).json({ msg: `No task with the id of ${req.params.id}` });
    }
})


module.exports = router;