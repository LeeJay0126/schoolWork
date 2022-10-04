import React, { useState, useRef, useEffect } from "react";
import { nanoid } from "nanoid";
import Form from "./components/Form";
import FilterButton from "./components/FilterButton";
import Todo from "./components/Todo";
import ToggleButton from "./components/ToggleButton";

function usePrevious(value) {
  const ref = useRef();
  useEffect(() => {
    ref.current = value;
  });
  return ref.current;
}

const FILTER_MAP = {
  All: () => true,
  Active: (task) => !task.completed,
  Completed: (task) => task.completed
}

const FILTER_NAMES = Object.keys(FILTER_MAP);

function App() {

  const [tasks, setTasks] = useState([]);
  const [filter, setFilter] = useState('All');
  const [theme, setTheme] = useState(false);

  useEffect(() => {
    const data = localStorage.getItem('listOfTasks');
    if (data) {
      setTasks(JSON.parse(data));
    }
  }, [])

  useEffect(()=> {
    const themeData = localStorage.getItem('themes');
    console.log(themeData);
    console.log(themeData === "true");
    if(themeData === "true"){
      setTheme(true);
    }else{
      setTheme(false);
    }
  },[])

  useEffect(() => {
    localStorage.setItem('listOfTasks', JSON.stringify(tasks));
  }, [tasks]);

  const taskList = tasks.filter(FILTER_MAP[filter]).map((task) => (
    <Todo
      id={task.id}
      name={task.name}
      completed={task.completed}
      key={task.id}
      toggleTaskCompleted={toggleTaskCompleted}
      deleteTask={deleteTask}
      editTask={editTask}
    />
  ));

  const filterList = FILTER_NAMES.map((name) => (
    <FilterButton key={name} name={name} isPressed={name === filter} setFilter={setFilter} />
  ));

  const tasksNoun = taskList.length !== 1 ? 'tasks' : 'task';
  const headingText = `${taskList.length} ${tasksNoun} remaining`;

  function deleteTask(id) {
    const remainingTasks = tasks.filter((task) => id !== task.id);
    setTasks(remainingTasks);
  }

  function editTask(id, newName) {
    const editedTaskList = tasks.map((task) => {
      if (id === task.id) {
        return { ...task, name: newName }
      }
      return task;
    });
    setTasks(editedTaskList);
  }

  function toggleTaskCompleted(id) {
    const updatedTasks = tasks.map((task) => {
      if (id === task.id) {
        return { ...task, completed: !task.completed }
      }
      return task;
    });
    setTasks(updatedTasks);
  }

  function addTask(name) {
    if (name !== '') {
      const newTask = { id: `todo-${nanoid()}`, name, completed: false };
      setTasks([...tasks, newTask]);
    }
  }

  const listHeadingRef = useRef(null);

  const prevTaskLength = usePrevious(tasks.length);
  useEffect(() => {
    if (tasks.length - prevTaskLength === -1) {
      listHeadingRef.current.focus();
    }
  }, [tasks.length, prevTaskLength]);

  function switchHandler() {
    setTheme(!theme);
    localStorage.setItem('themes',theme);
  }

  function clearData(){
    localStorage.clear();
    setTasks([]);
  };


  return (
    <div className={theme ?  `todoapp stack-large darkTheme` : `todoapp stack-large`}>
      <ToggleButton onSwitchHandler={switchHandler}></ToggleButton>
      <h1 >TodoMatic</h1>
      <Form addTask={addTask} />
      <div className="filters btn-group stack-exception">
        {filterList}
      </div>
      <h2 id="list-heading" tabIndex="-1" ref={listHeadingRef}>{headingText}</h2>
      <ul
        className="todo-list stack-large stack-exception"
        aria-labelledby="list-heading"
      >
        {taskList}
      </ul>
      <div className="btn-group">
        <button className="btn" onClick={() => clearData()}>Clear</button>
      </div>
    </div>
  );
}

export default App;
