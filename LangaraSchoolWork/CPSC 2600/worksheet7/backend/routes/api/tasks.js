const express = require('express');
const router = express.Router();
const tasks = require('../../Tasks');
const uuid = require('uuid');

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
    const found = tasks.some(task => task.id === parseInt(req.params.id));

    if(found) {
        res.json(tasks.filter(task => task.id === parseInt(req.params.id)));
    }
    else {
        res.status(400).json({msg: `Unable to find Task ID: ${req.params.id}`});
    }
});


/**
 * @ TODO Task 2
 * @route DELETE api/tasks/:id
 * @desc Deletes task with ID specified in URL
 **/
 router.delete('/:id', (req, res) => {
    const found = tasks.some(task => task.id === parseInt(req.params.id));

    if(found) {
        res.json({
            msg: `Removed Task ID: ${req.params.id}`,
            tasks: tasks.filter(task => task.id !== parseInt(req.params.id))
        });
    }
    else {
        res.status(400).json({msg: `Unable to find Task ID: ${req.params.id}`});
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
    };

    if(!newTask.taskName) {
        res.status(400).json({msg: `400 Bad Request! No task name provided`});
    }
    else {
        tasks.push(newTask);
        res.json(tasks);
    }
    
});

module.exports = router;